#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int f_orig = open("ex1.txt",O_RDWR);
    int f_cop = open("ex1.memcpy.txt",O_RDWR);
    
    struct stat statbuf;
    
    fstat(f_orig,&statbuf);
    ftruncate(f_cop,statbuf.st_size);
    
    char *orig = mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,f_orig,0);
    char *extr = mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,f_cop,0);
    
    memcpy(extr,orig,statbuf.st_size);

    
    
    return 0;
}


