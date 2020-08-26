#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void ex1(){
    printf("exercise 1\n");
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("sizes of: \nint %lu\nfloat %lu\ndouble %lu\n",sizeof(int),sizeof(float),sizeof(double));
    printf("\nmax int %d\nmax float %f\nmax double %f\n",i,f,d);
}

int main() {
    ex1();
    return 0;
}
