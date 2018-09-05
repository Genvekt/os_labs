#include <stdio.h>
#define SIZE_ARR 10

int main(){
    int array[SIZE_ARR] = {7,3,8,4,7,3,8,4,7,3};
    bubble_sort(array, SIZE_ARR);
    int size2 = sizeof(array)/ sizeof(array[0]);
    for(int i = 0; i<size2; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

int bubble_sort(int* arr, int size){
    int sorted = 0;
    printf("%d\n",size);
    while(sorted == 0){
        sorted = 1;
        for(int i = 0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] =arr[i+1];
                arr[i+1] = temp;
                sorted = 0;
            }
        }
    }
    return 0;
}
