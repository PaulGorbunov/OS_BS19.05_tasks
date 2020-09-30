#include <stdio.h>  
int main() {  
    char **s; 
    char foo[] = "Hello World"; 
//     *s=foo;                          //Fix tricks
    s = *(&foo);                        //fixed
    printf("s is %s\n",s); 
//     s[0] = foo;                      //Fix tricks
    *(&s) = &foo;                       //fixed
    printf("s[0] is %s\n",(&s)[0]);     //fixed
    return(0);  
} 
