#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(){

    int error = fork();

    if(error <0){
        return EXIT_FAILURE;
    }
    else if(error == 0){
        //it is child process
        while(1){
            printf("<CHILD>: I'm alive! \n");
             sleep(1);
        }
    }
    else{
        //it is parent
        sleep(10);
        kill (0, SIGTERM); //send SIGTERM signal to child 
    }
    return  EXIT_SUCCESS;
}