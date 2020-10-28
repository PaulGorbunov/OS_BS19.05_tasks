#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    char *mess = "This is a nice day";    
    size_t mess_size = strlen(mess) + 1;  //message's size
    FILE *file = fopen("ex1.txt","w");    
    
    ftruncate(fileno(file),mess_size-1);  //get file's description
    fclose(file);
    
    int i_file = open("ex1.txt",O_RDWR);
    
    char *map;
    map = mmap(NULL,mess_size, PROT_READ|PROT_WRITE, MAP_SHARED,i_file,0);  //mapping into the memory
    for (size_t u = 0; u < mess_size;u++){
        map[i] = mess[i];
    }
    
    return 0;
}
