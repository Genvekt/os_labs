#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int next_command(char* command){
    printf("-> ");
    gets(command);
}
int main(){
    printf("Welcome to my mini shell!\n");

    char command[100];
    char** args[100];

    while(1){
        next_command(command);
        args[0] = command;
        size_t len =  strlen(command);
        int arg_count = 1;
        char* next = command;

        //parse all arguments
        while((next = strchr(next,' ')) != NULL){
            int space_num = strspn(next," ");
            *next = '\0';
            next += space_num;
            args[arg_count] = next;
            arg_count += 1;
        }
        //case for background process
        if(args[arg_count-1][0] == '&'){
            int pid = fork();
            if(pid == 0){
                //child process
                args[arg_count-1] = NULL;
                execvp(args[0], args);
                return EXIT_SUCCESS;
            }
            //parent process goes on next loop
        }
        //regular case
        else{
            args[arg_count] = NULL;
            execvp(args[0], args);
        }
        
    }


}