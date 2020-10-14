#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_N 30
#define _FRAMES 100

typedef struct page_info{
    int id;
    struct mark{
        unsigned int m:BIT_N;
    }mark;
}page_inf ;


typedef struct main_mem_pages{
    int used;                              // the length of the linked list
    page_inf *pages[_FRAMES];              // the pages in the main memory with the _FRAMES size
}main_mem;


void change_node(page_inf *val,int ac){           // changing node (its usage score)
    val->mark.m >>=1;
    if (ac == 0){
        val->mark.m += (1<<(BIT_N-1));
    }
}

page_inf *cr_page(int id){                       // creating node
    page_inf *p = malloc(sizeof(page_inf));
    p->id = id;
    p->mark.m = (1<<(BIT_N-1));
    return p;
}

int list_repl(main_mem *lis,int id){            // if main memory is all used, replace the less used page
    int s = 1<<(BIT_N);                         // for the new one
    int rep;
    for (int u = 0;u<lis->used;u++){
        if (lis->pages[u]->mark.m < s){
            s = lis->pages[u]->mark.m;
            rep = u;
        }
    }
    lis->pages[rep] = cr_page(id);
}

int list_add(main_mem *lis,int id){          // adding new page to the main memory
    if (lis->used == _FRAMES){
        list_repl(lis,id);
        
    }else{
        *(lis->pages+(lis->used)) = cr_page(id);
        lis->used += 1; 
    }
}


void list_change_all_ex(main_mem *lis,int id,int fl){     // change usage for the pages in the main memory
    for (int u = 0;u<lis->used;u++){
        if (lis->pages[u]->id == id){
            if (fl){
                change_node(lis->pages[u],0);
            }
        }else{
            change_node(lis->pages[u],1);
        }
    }
}

void print_node(main_mem *lis){                          // printing liked list
    for (int u = 0;u<lis->used;u++){
        printf("%d -> %d\n",lis->pages[u]->id,lis->pages[u]->mark.m);
    }
    putc('\n',stdout);
}
char * get_inp() {                                          //reading string from the input file
    FILE *file;
    char filename[] = "Lab 09 input test.txt";              // from file
    file = fopen(filename, "rb");
    char *string = malloc(sizeof(char));
    *string = 0;
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);
        string = malloc((unsigned) size + 1);
        fread(string, 1, (unsigned)size, file);
        fclose(file);
        string[size] = 0;
    }
    return string;
}

int in(main_mem *mem,int find){                      // checking if element is in the linked list (main mem)
    for (int u = 0;u<mem->used;u++){
        if (find == mem->pages[u]->id){
            return 1;
        }
    }
    return 0;
}

void start_paging(char *ord){
    float hit = 0.0;           // hit & miss counters
    float miss = 0.0;
    main_mem m_lis;            // main memory representation (1-st page in linked list)
    m_lis.used = 0;            // the main memory usage variable
    for (int y = 0;*(ord+y) != 0;y++){           // 
        int k = 0;
        for (;*(ord+y) != ' ' && *(ord+y) != 0;y++,k++);  // pass for ' ' chars in the input string
        char *st = malloc(sizeof(char)*k+1);
        *(st+k) = 0;
        for (int g = 0;y-k >= 0 && *(ord+y-k) != ' '&& k>=0;k--,g++){    // getting the number of the page from the string
            *(st+g) = *(ord+y-k);
        }
        int page_rec;
        sscanf(st, "%d", &page_rec);           // turning string page number into the integer
        if (in(&m_lis,page_rec)){             // checking if needed page is in the main memory
            hit ++;                            // if so, hit++
            list_change_all_ex(&m_lis,page_rec,1);  // and change page's usage score
        }else{
            miss ++;                           //else miss++
            list_add(&m_lis,page_rec);         // adding page to the main memory
            list_change_all_ex(&m_lis,page_rec,0);   // and change page's usage score
        }
    }
    printf("hit(%d)/miss(%d) = %f \n",(int)hit,(int)miss,hit/miss);
}

int main(){
    char *input = get_inp();
    start_paging(input);
    return 0;
}


