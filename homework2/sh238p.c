#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <glob.h>

#define SH_TOK_BUFSIZE 64
#define SH_TOK_DELIM " \t\r\n\a"
#define MAX_HISTORY_SIZE 500

static char *cmd_history[MAX_HISTORY_SIZE];
static int history_count = 0;

void sh_redir(char* file, int mode, int permission, int fd);
void add_history(const char *cmd);
void print_history();

/**
 ** @brief Launch a program and wait for it to terminate.
 ** @param args Null terminated list of arguments (including program).
 ** @return Always returns 1, to continue execution.
 */
int sh_launch(char **args){
    /* most of your code here */
    int status;

    pid_t pid = fork();
    if (pid < 0) {
        perror("sh238p: error in forking");
    }
    else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "sh238p: error when executing %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else {
        do {
            pid_t wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}


/**
 ** @brief Execute shell built-in or launch program.
 ** @param args Null terminated list of arguments.
 ** @return 1 if the shell should continue running, 0 if it should terminate
 */
int sh_execute(char **args){
    if (args[0] == NULL) {
        return 1;  // An empty command was entered.
    }
    char **args_pointer = args;
    int pd[2];

    for(; *args_pointer; args_pointer++) {
        switch (**args_pointer) {
            case '>':
                *args_pointer = NULL;
                sh_redir(*(args_pointer + 1), O_RDWR | O_CREAT, 0666, 1);  // 0666 stands for RW- on each group
                break;
            case '<':
                *args_pointer = NULL;
                sh_redir(*(args_pointer + 1), O_RDONLY, 0444, 0);  // R-- on each group
                break;
            case '|': {  // support pipeline
                *args_pointer = NULL;
                pipe(pd);  // pipe the io
                if (fork() == 0) {
                    close(1);
                    dup(pd[1]);
                    close(pd[0]);
                    close(pd[1]);
                    execvp(args[0], args);
                    fprintf(stderr, "exec %s failed\n", args[0]);
                    exit(EXIT_FAILURE);
                }
                if (fork() == 0) {
                    close(0);
                    dup(pd[0]);
                    close(pd[0]);
                    close(pd[1]);
                    return sh_execute(args_pointer + 1);
                }

                close(pd[0]);
                close(pd[1]);
                wait(NULL);
                wait(NULL);
                return 1;
            }
            case ';':  // Support for  ;  separated commands in one line
                *args_pointer = NULL;
                return sh_execute(args) && sh_execute(args_pointer + 1);
            case '&':  // Support for  &  for background processes
                if (*(args_pointer + 1) == NULL) {
                    *args_pointer = NULL;
                    int id = fork();
                    int status;
                    if (id == 0) {
                        execvp(args[0], args);
                        fprintf(stderr, "Exec %s failed\n", args[0]);
                        exit(EXIT_FAILURE);
                    }
                    waitpid(-1, &status, WNOHANG);
                    return 1;
                }
                break;
        }
    }

    return sh_launch(args);   // launch
}

void sh_redir( char* file, int mode, int permission, int fd) {
    close(fd);
    if (open(file, mode, permission) < 0) {
        fprintf(stderr, "Fail to open %s\n", file);
        exit(EXIT_FAILURE);
    }
}

void add_history(const char *cmd) {
    if (history_count < MAX_HISTORY_SIZE)
        cmd_history[history_count++] = strdup(cmd);  // strdup allocates memory for the new string on the heap
    else {
        // move history forward and make room for the new one
        free(cmd_history[0]);
        int i;
        for (i = 1; i < MAX_HISTORY_SIZE; i++)
            cmd_history[i - 1] = cmd_history[i];
        cmd_history[MAX_HISTORY_SIZE - 1] = strdup(cmd);
    }
}

void print_history() {
    int i;
    for (i = 0; i < history_count; i++) {
        printf("%d %s", i + 1, cmd_history[i]);
    }
}


/**
 ** @brief Split a line into tokens (very naively).
 ** @param line The line.
 ** @return Null-terminated array of tokens.
 */

char **sh_split_line(char *line){
    int bufsize = SH_TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token, **tokens_backup;

    if(!tokens){
        fprintf(stderr, "sh238p: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, SH_TOK_DELIM);
    while(token != NULL){
        tokens[position] = token;
        position++;

        if(position >= bufsize){
            bufsize += SH_TOK_BUFSIZE;
            tokens_backup = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if(!tokens){
                free(tokens_backup);
                fprintf(stderr, "sh238p: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        // On the first call to strtok(), the string to be parsed should be specified in str.
        // In each subsequent call that should parse the same string, str must be NULL.
        token = strtok(NULL, SH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

/**
 ** @brief Read a line of input from stdin.
 ** @return The line from stdin.
 **/
char *sh_read_line(void){
    char *line = NULL;
    size_t bufsize = 0; // have getline allocate a buffer for us
    if(getline(&line, &bufsize, stdin) == -1){
        if (feof(stdin)){ // We receive an EOF
            // fprintf(stderr, "EOF\n");
            exit(EXIT_SUCCESS);
        }else{
            perror("sh238p: sh_read_line");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

/**
 ** @brief Loop getting input and executing it.
 **/
void sh_loop(void){
    char *line;
    char **args;
    int status;

    int stdin_backup = dup(0);
    int stdout_backup = dup(1);

    do{
        printf("238p$ ");
        line = sh_read_line();

        add_history(line);  // Support for history

        if (line[0] == 'c' && line[1] == 'd' && line[2] == ' ') {  // Support for cd
            line[strlen(line) - 1] = 0;
            if (chdir(line + 3) < 0)
                fprintf(stderr, "cannot cd %s\n", line + 3);
            status = 1;
            continue;
        }

        args = sh_split_line(line);

        if (args[0] && strcmp(args[0], "history") == 0 && args[1] == NULL) {
            print_history();
            status = 1;
            continue;
        }

        status = sh_execute(args);

        free(line);
        free(args);

        dup2(stdin_backup,0);
        dup2(stdout_backup,1);
    } while(status);
}


/**
 ** @brief Main entry point.
 ** @param argc Argument count.
 ** @param argv Argument vector.
 ** @return status code
 **/
int main(int argc, char **argv){
    sh_loop();
    return EXIT_SUCCESS;
}
