# cs 238P  
## Homework 5

1. Add the following in `syscall.c`.  
```c
extern int sys_newproc ( void ) ;
```
2. Add the following in `syscall.h`.  
```c
# define SYS_newproc 22
```
3. Add the following to the array of functions in `syscall.c`.  
```c
[ SYS_newproc ] sys_newproc
```
4. Define the sys newproc call. This definition will be given in `sysproc.c`.   

5. Add the following in `usys.S`.    
```c
SYSCALL ( newproc )
```

6. Added to `defs.h` to include `newproc()`  
```c
int newproc(const char*, const char**);
```

7. Add the following in `user.h`  ·
```c
int newproc(const char *pathname, const char** args);
```

8. Finally, implement `newproc()` in `proc.c`  

### How it works  
`newproc` call will create a new process. On successful invocation, `newproc` will return the process ID of the new process. If the arguments passed to the function are incorrect return -1. If there is any other error, return -2.  

`newproc`  combines the functionality of fork and exec in one single system call.  

First we allocate process, then copy process state from proc. Next we put current proc id into `%eax`.  This is the end of fork part.

Then we execute the new process. After checking ELF header, load program into memory. Allocate two pages at the next page boundary. Make the first inaccessible, and use the second as the user stack.  Push argument strings, prepare rest of stack in `ustack`. Commit to the user image, mark current process as `RUNNABLE`. Finally return current `pid`.  




