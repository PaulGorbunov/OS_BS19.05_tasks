#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute(char c[100]) {
    system(c);
}

int main() {
    char req[100];
    while (1) {
        system("sleep 0.1");
        printf(":>>> ");
        fgets(req,100,stdin);
        if (fork() == 0) {
            execute(req);
            return 0;
        }
    }
    
    return 0;
}
