#include <stdlib.h>
#include <stdio.h>
#define MESLEN 19
char *message = "Hello through pipe";

int main(){
    char destination[MESLEN];
    int io[2];

    int error = pipe(io);
    if(error<0){
        return EXIT_FAILURE;
    }

    write(io[1], message, MESLEN);
    read(io[0], destination, MESLEN); 
    printf("%s\n",destination);
    return  EXIT_SUCCESS;
}