#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("What is the number of elements in the array?\n");
    int n = 0;

    do{
        scanf("%d",&n);
        if(n<=0){
            printf("Size must be greater than zero! Try again, please.\n");
        }
    }while(n<=0);


    int *array = malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        array[i] = i;
    }
    printf("Your array is:");
     for(int i = 0; i<n; i++){
        printf(" %d",array[i]);
    }

    free(array);

    printf("\n");

    return EXIT_SUCCESS;



}