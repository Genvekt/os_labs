#include <stdio.h>
#include <stdlib.h>

int main(){
    char*ptr;
    for(int i = 0; i<10;i++){               //every 10 secinds
        ptr = malloc(10485760*sizeof(char)); //allocate 10 Mb 
        memset(ptr,0,10485760*sizeof(char)); //fill with zeros
        sleep(1);
    }
    return EXIT_SUCCESS;
}