#include <stdio.h>
#include <stdlib.h>

int next_command(char* command){
    printf("-> ");
    scanf("%s",command);
}
int main(){
    printf("Welcome to my mini shell!\nTo exit type 'exit_mini_shell'.\n");
    char command[15];
    while(1){
        //read command
        next_command(command); 
        if(!strcmp(command, "exit_mini_shell")){
            printf("The mini shell is closed.\n");
            return EXIT_SUCCESS;
        }
        else{
            //run command
            system(command);
        }
    }
}
