#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void ex3(){
    printf("exercise 3\n");
    printf("input height:\n");
    int n ;
    char ch[100];
    fgets(ch,LINE_MAX,stdin);
    sscanf(ch, "%d",&n);
    if (n < 0) return;
    int l = 2*n-1;
    char out[l+1];
    for (int h = 0;h<l;h++){
        out[h] =' ';
    }
    out[l] = '\0';
    for (int g = 0;g!=n;g++){
        out[l/2 + g] = '*';
        out[l/2 - g] = '*';
        printf("%s\n",out);
    }
}



int main() {
    ex3();
    return 0;
}
