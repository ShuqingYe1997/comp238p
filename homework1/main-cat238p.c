#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

void file_copy(int in_fd, int out_fd);

int main(int argc, char *argv[]) {
    int fd;
    if (argc <= 1) {
        /* no argument is given, get from stdin and write to stdout. */
        file_copy(STDIN, STDOUT);
    }
    else {
        /* one argument is provided, displays the contents on standard output */
        int i = 1;
        for(; i < argc; i++) {
            if ((fd = open(argv[i], O_RDONLY)) < 0) {
                char msg[] = "cat: cannot open\n";
                write(STDERR, msg, sizeof(msg));
            }
            else {
                file_copy(fd, STDOUT);
                close(fd);
            }
        }
    }
    return 0;
}

void file_copy(int in_fd, int out_fd)
{
    int n;
    char buf[BUFSIZ];

    /* read and write using the system calls. */
    while ((n = read(in_fd, buf, BUFSIZ)) > 0) {
        if (write(out_fd, buf, n) != n) {
            char msg[] = "cat: write error\n";
            write(STDERR, msg, sizeof(msg));
        }
    }
    if(n < 0){
        char msg[] = "cat: read error\n";
        write(STDERR, msg, sizeof(msg));
    }
}