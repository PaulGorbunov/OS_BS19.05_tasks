#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int f_orig = open("ex1.txt",O_RDWR);               //opening files
    int f_cop = open("ex1.memcpy.txt",O_RDWR);
    
    struct stat buf;
    
    fstat(f_orig,&buf);
    ftruncate(f_cop,buf.st_size);
    
    char *orig = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,f_orig,0);   //mapping into the memory
    char *extr = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,f_cop,0);
    
    memcpy(extr,orig,buf.st_size);

    
    
    return 0;
}


