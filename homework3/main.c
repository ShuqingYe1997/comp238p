#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <sys/mman.h>


#include <sys/types.h>
#include <unistd.h>

// Format of an ELF executable file

#define ELF_MAGIC 0x464C457FU  // "\x7FELF" in little endian

// File header
struct elfhdr {
    unsigned int magic;  // must equal ELF_MAGIC
    unsigned char elf[12];
    unsigned short type;
    unsigned short machine;
    unsigned int version;
    unsigned int entry;
    unsigned int phoff;
    unsigned int shoff;
    unsigned int flags;
    unsigned short ehsize;
    unsigned short phentsize;
    unsigned short phnum;
    unsigned short shentsize;
    unsigned short shnum;
    unsigned short shstrndx;
};

// Program section header
struct proghdr {
    unsigned int type;
    unsigned int off;
    unsigned int vaddr;
    unsigned int paddr;
    unsigned int filesz;
    unsigned int memsz;
    unsigned int flags;
    unsigned int align;
};

// Values for Proghdr type
#define ELF_PROG_LOAD           1

// Flag bits for Proghdr flags
#define ELF_PROG_FLAG_EXEC      1
#define ELF_PROG_FLAG_WRITE     2
#define ELF_PROG_FLAG_READ      4

int main(int argc, char* argv[]) {
    struct elfhdr elf;
    struct proghdr ph;
    int (*sum)(int a, int b);
    void *entry = NULL;
    int ret;

    /* Add your ELF loading code here */

    // alloc array of section header entries
    int fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        // open failed
        close(fd);
        perror("Open elf failed.");
        return -1;
    }
    if (read(fd, &elf, sizeof(struct elfhdr)) < 0) {
        // read failed
        perror("Read elf failed.");
        close(fd);
        return -1;
    }
    if (elf.magic != ELF_MAGIC) {
        // wrong file structure
        perror("Wrong elf structure.");
        close(fd);
        return -1;
    }
    lseek(fd, elf.phoff, SEEK_SET);

    // load section header entries, load symbol table and relocs, map sections
    int i = 0;
    void *code_va = NULL;
    for (; i < elf.phnum; i++) {
        if (read(fd, &ph, sizeof(struct proghdr)) < 0) {
            // read program header failed
            perror("Read program header failed.");
            close(fd);
            return -1;
        }
        if (ph.type == ELF_PROG_LOAD &&
        ph.flags == (ELF_PROG_FLAG_EXEC | ELF_PROG_FLAG_WRITE | ELF_PROG_FLAG_READ)) {
            code_va = mmap(NULL, ph.memsz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
            pread(fd, code_va, ph.memsz, ph.off);
            break;
        }
    }

    entry = code_va;
    close(fd);

    if (entry != NULL) {
        sum = entry;
        ret = sum(1, 2);
        printf("sum:%d\n", ret);
    };

    return 0;
}

