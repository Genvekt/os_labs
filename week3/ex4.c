#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARR 10

int main(){
    int array[SIZE_ARR] = {7,4,8,4,7,4,8,4,7,3};
    quick_sort(array, 0, SIZE_ARR - 1);
    int size2 = sizeof(array)/ sizeof(array[0]);
    for(int i = 0; i<10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

int quick_sort(int* array, int start, int end){
    //base case
    if(start == end|| start>end){
        return 0;
    }
    //partition part
    else{
        int pivot = array[end];
        int wall = start; //first element of the second sub array
        for(int i = start; i<end; i++){
            if(array[i]<=pivot){
                int temp = array[wall];
                array[wall] = array[i];
                array[i] = temp;
                wall++;
            }
        }
        array[end] = array[wall];
        array[wall] = pivot;

        //solving sub problems
        quick_sort(array,start,wall-1);
        quick_sort(array,wall,end);
    }
}
