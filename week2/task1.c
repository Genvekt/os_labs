
#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    int int_size = sizeof(int);
    int float_size = sizeof(float);
    int double_size = sizeof(double);

    printf("Size of integer is %d bytes. Max integer is %d\nSize of float is %d bytes. Max float is %f\nSize of double is %d bytes. Max double is %lf.", int_size, a, float_size, b, double_size, c);
    printf("\n");
    return 0;
}