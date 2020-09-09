#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int n = fork();
    if (n > 0) {
         printf("hello from parent[%d - %d]\n", getpid(), n);
    }else if(n == 0){
        printf("hello from child[%d - %d]\n", getpid(), n);
    }else {
       printf("error in fork()");
       return 1;
    }
    return 0;
}
