#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* sourse = fopen("/dev/urandom", "r");
    FILE* destination = fopen("ex1.txt","w");
    if (sourse < 0)
    {
        return EXIT_FAILURE;
    }
    else{
        char randomString[20];
        size_t res = fread(randomString,sizeof(char),20,sourse);
        if(res<0 | res<20){
            printf("Read less data than expected\n");
            return EXIT_FAILURE;
        }
        printf("I have read %d random characters\n",res);
        printf("My random string is '%s'\n", randomString);

        //output to file
        fprintf(destination,"My random string is '%s'\n",randomString);
       


    }
    fclose(sourse);
    fclose(destination);
     return EXIT_SUCCESS;
}