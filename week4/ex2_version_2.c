#include <stdio.h>
#include <stdlib.h>
#define LOOPS 5

int main(){
    for(int i = 0; i < LOOPS; i++){
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
    
}