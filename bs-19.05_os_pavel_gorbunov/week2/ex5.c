#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void ex5(){
    printf("exercise 5\n");
    printf("input height(any int) and type(0,1,2) with space separation:\n");
    int n ;
    int t ;
    fscanf(stdin,"%d %d",&n,&t);
    if (n < 0) return;
    if (t>2 || t<0)return;
    int l = n;
    char out[l+1];
    for (int h = 0;h<l;h++){
        if (t == 2){
            out[h] ='*';
            continue;
        }
        out[h] =' ';
    }
    out[l] = '\0';
    for (int g = 0;g!=n;g++){
        if (t==1 && ((n%2 != 0 && g > n/2 ) || (n%2 == 0 && g >= n/2 ))){
            out[n-g] = ' ';
        }else if (t != 2){
            out[g] = '*';
        }
        printf("%s\n",out);
    }

}
int main() {
    ex5();
    return 0;
}
