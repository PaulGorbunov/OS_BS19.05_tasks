#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void ex2(){
    printf("exercise 2\n");
    printf("input string:\n");
    char s[100];
    fgets(s,LINE_MAX,stdin);
    unsigned int s_len = strlen(s);
    for(int u =(int) s_len-1;u>=0;--u){
        putc(s[u],stdout);
    }
    printf("\n");
}

int main() {
    ex2();
    return 0;
}
