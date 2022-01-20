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

    static unsigned int ptd_address[1024]  __attribute__ ((aligned (4096)));;

    int n = 0;
    int m = 0;
    int mark = 0b00000011;

    for (; n < 64; n++)
    {
        static unsigned int page_table[1024] __attribute__ ((aligned (4096)));
        ptd_address[n] = (unsigned int)page_table | mark;
        for (; m < 1024 * (n + 1); m++)
        {
            page_table[m] = (0x1000 * m) | mark;
        }
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


