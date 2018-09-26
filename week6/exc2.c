#include <stdlib.h>
#include <stdio.h>
#define MESLEN 11
char *message = "New string";

int main(){
    char destination[MESLEN] = "Old string";
    int io[2], reading;

    int error = pipe(io);
    if(error<0){
        return EXIT_FAILURE;
    }

    error = fork();

    if(error <0){
        return EXIT_FAILURE;
    }
    else if(error == 0){
        //it is child process
        close(io[1]); //close output;
        reading = read(io[0], destination, sizeof(destination));
        printf("<CHILD>: %s\n",destination);
    }
    else{
        //it is parent
        close(io[0]); //close input;
        write(io[1],message,MESLEN);
        printf("<PARENT>: %s\n",destination);
    }
    return  EXIT_SUCCESS;
}