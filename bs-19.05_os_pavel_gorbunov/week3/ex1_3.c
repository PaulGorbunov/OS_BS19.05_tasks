#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h> 

int len = 7;
int array[7]= {3205, 104322, 27387, 34065, 50993, 68520, 8977}

typedef struct node{
    int val;
    struct node* next;
    
}node;

typedef struct pass{
    int len;
    int* arr;
    
}pass;

node* create_linked_list(){
    node* head = (node *) malloc(sizeof(node));
    head->next = NULL;
    return head;
    
}

void insert_node(node* head,int ind,int val){
    node* new = create_linked_list();
    new->val = val;
    node *tmp = head;
    for(int i = 0;i<ind;i++){
        if (tmp->next != NULL){
            tmp = tmp->next;
            
        }else break;
    }
    new->next = tmp->next;
    tmp->next = new;    
}

int delete_node(node* head,int ind){
    if (ind == 0){
        node *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
        return 0;
    }
    int i;
    node *tmp = head;
    for(i = 0;i<ind;i++){
        if (tmp->next->next != NULL){
            tmp = tmp->next;
        }else break;
    }
    if (i != (ind))return 1;
    node* n = tmp->next;
    tmp->next = n->next;
    free(n);
    return 0;
}

void print_list(node *head){
    node *tmp = head->next;
    while(tmp != NULL){
        printf("%d ",tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void ex3(){
    node* head = create_linked_list();
    insert_node(head,0,1);
    insert_node(head,1,2);
    insert_node(head,2,4);
    insert_node(head,2,3);
    insert_node(head,4,5);
    insert_node(head,0,0);
    print_list(head);
    delete_node(head,0);
    delete_node(head,3);
    delete_node(head,3);
    delete_node(head,3);
    print_list(head);
    
    
}

int ex1(){
    int* pc;
    int c;
    c=22;
    printf("Address of c:%p\n",(void *)&c);
    printf("Value of c:%d\n\n",c);
    pc=&c;
    printf("Address of pointer pc:%p\n",(void *)pc);
    printf("Content of pointer pc:%d\n\n",*pc);
    c=11;
    printf("Address of pointer pc:%p\n",(void *)pc);
    printf("Content of pointer pc:%d\n\n",*pc);
    *pc=2;
    printf("Address of c:%p\n",(void *)&c);
    printf("Value of c:%d\n\n",c);
    return 0;
}


void boublesort(int *arr,int len){
    for (int u = 0;u<len-1;u++){
        for(int g = 0;g<len-u-1;g++){
            if (*(arr+g)>*(arr+g+1)){
                int tmp = *(arr+g);
                *(arr+g) = *(arr+g+1);
                *(arr+g+1) = tmp;
            }
        }
    }
    
}

void ex2(){
    int i[5] = {5,4,3,2,1};
    boublesort(i,5);
    for (int u = 0;u<5;u++){
        printf("%d ",i[u]);
    }
    printf("\n");
    
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
void *quicksort(void *inp){
    int *arr = ((pass*)inp)->arr;
    int len =  ((pass*)inp)->len;
    int piv = *(arr+len-1);
    int i = -1;
    for (int g = 0;g<len;g++){
        if (*(arr+g)<=piv){
            ++i;
            swap((arr+i),(arr+g));
        }
    }
    pthread_t lef;
    pthread_t rig;
    if(len > 0){
        void *f = malloc(sizeof(pass));
        ((pass*)f)->len = i;
        ((pass*)f)->arr = arr;
        pthread_create(&lef,NULL,quicksort,f);
    }
    if(len-i-1 > 0 ){
        void *f = malloc(sizeof(pass));
        ((pass*)f)->arr = arr+i;
        ((pass*)f)->len = len-i;
        pthread_create(&rig,NULL,quicksort,f);
    }
    if(len > 0)pthread_join(lef,NULL);
    if(len-i-1 > 0 )pthread_join(rig,NULL);
}

void _quicksort(int *arr,int len){
    int piv = *(arr+len-1);
    int i = -1;
    for (int g = 0;g<len;g++){
        if (*(arr+g)<=piv){
            ++i;
            swap((arr+i),(arr+g));
        }
    }
    if(len > 0){
        _quicksort(arr,i);
    }
    if(len-i-1 > 0 ){
        _quicksort(arr+i,len-i);
    }
}

void ex4(){
    clock_t t; 
    
    t = clock();
    
    pthread_t m;
    void *f = malloc(sizeof(pass));
    ((pass*)f)->arr = array;
    ((pass*)f)->len = len;
    pthread_create(&m,NULL,quicksort,f);
    pthread_join((pthread_t)m,NULL);
    
    t = clock() - t;
    printf("%f\n",((double)t)/CLOCKS_PER_SEC); 


/*    t = clock();  
    boublesort(array,len);
    t = clock() - t;
    printf("%f\n",((double)t)/CLOCKS_PER_SEC);*/   
    
//     t = clock();  
//     _quicksort(array,len);
//     t = clock() - t;
//     printf("%f\n",((double)t)/CLOCKS_PER_SEC);
    
    
//     for (int u = 0;u<len;u++){
//         printf("%d ",array[u]);
//     }
//     printf("\n");
    
}
int main(){
    printf("ex2\n");
    ex2();
    printf("ex3\n");
    ex3();    
    printf("ex4\n");
    ex4();
    
}
