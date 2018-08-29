#include <stdio.h>
int main(){
    int first,second;
    printf("Enter a first int ");
    scanf("%d", &first);
    printf("Enter a second int ");
    scanf("%d", &second);
    swap(&first,&second);
    printf("First now is %d, and second is %d\n",first,second);
}

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}


