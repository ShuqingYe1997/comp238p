#include "console.h"

static inline void lcr3(unsigned int val){
    asm volatile("movl %0,%%cr3" : : "r" (val));
}

static inline void halt(void){
    asm volatile("hlt" : : );
}

int main(void){
    int i;
    int sum = 0;
    // Initialize the console
    uartinit(); 
    printk("Hello from C\n");
    // Create your page table here
    // lcr3(ptd_address);

    int mark = 0b00000011;
    int m, n;

    static unsigned int ptd_address[1024]  __attribute__ ((aligned (4096)));;
    static unsigned int page_table1[1024]  __attribute__ ((aligned (4096)));;
    static unsigned int page_table2[1024]  __attribute__ ((aligned (4096)));;

    ptd_address[0] = (unsigned int)page_table1 | mark;
    ptd_address[1] = (unsigned int)page_table2 | mark;

    for (m = 0; m < 1024; m++)
    {
        page_table1[m] = (0x1000 * m) | mark;
    }

    for (n = 1024; n < 2048; n++)
    {
        page_table2[n - 1024] = (0x1000 * n) | mark;
    }

    lcr3((unsigned int)ptd_address);
    
    for (i = 0; i < 64 /*64*/; i++) {
        int *p = (int *)(i * 4096 * 32);
        sum += *p; 
        printk("page\n"); 
    }
    halt();
    return sum; 
}


