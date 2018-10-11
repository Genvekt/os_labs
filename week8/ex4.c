#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
    char*ptr;
    struct rusage usage;
    for(int i = 0; i<10;i++){               //every 10 secinds
        ptr = malloc(10485760*sizeof(char)); //allocate 10 Mb 
        memset(ptr,0,10485760*sizeof(char)); //fill with zeros
        getrusage(RUSAGE_SELF, &usage );
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return EXIT_SUCCESS;
}