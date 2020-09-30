#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("N-> ");
    scanf("%d", &N);
    int* list = malloc(N* sizeof(int));     // allocating the memory for the list with size N
    for (int u = 0; u < N; u++) {
        list[u] = u;                        // filling the list
    }
    printf("The list->");
    for (int u = 0; u < N; u++) {
        printf("%d ",list[u]);             //printing the list
    }
    printf("\n");
    free(list);
    return 0;
}
    
