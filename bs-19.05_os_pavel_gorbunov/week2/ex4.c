#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void ex4(){
    printf("exercise 4\n");
    printf("input two numbers (a,b) with space separator:\n");
    int a,b;
    fscanf(stdin,"%d %d",&a,&b);
    swap(&a,&b);
    printf("swapped: a = %d, b = %d \n",a,b);

}


int main() {
    ex4();
    return 0;
}
