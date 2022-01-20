#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

unsigned long sum(int n) {
    int i;
    unsigned long sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + i;
    }

    return sum;
}

int a[32]; // the global array

unsigned long crash_array(int n) {
    if (n < 0 || n > 31) {
        return 0;
    }
    int i;
    unsigned long sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + a[i];
    }

    return sum;
}

int main(void) {
    unsigned long s;
    s = sum(100);
    printf("Hello world, the sum:%ld\n", s);

    s = crash_array(100000);
    printf("crash array sum:%ld\n", s);

//    int nums[] = {-1, 0, 1, 31, 32, 1000};
//    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
//        s = crash_array(nums[i]);
//        printf("crash array sum:%ld\n", s);
//    }
    return 0;
}