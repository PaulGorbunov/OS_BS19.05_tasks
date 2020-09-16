#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define L 10

int prod_sp,cons_sp;                                   // sleep/awake for producer and consumer
int buffer[L];                                         // shared buffer
int TIME;                                              // shared counter
int P =1000000;                                        // to print once in a while.
long long int print = 0;

void *thread_f(void *varg){
    if (!*((int*)varg)){                                // Producer
        printf("I am producer\n");
        while (1){
            if (prod_sp) continue;
            if (TIME == L){
                prod_sp = 1;
                cons_sp = 0;
                continue;
            }
            print++;
            if ((print)%P == 0 && print >= P) printf( "Prod %d %d\n",buffer[TIME],TIME);
            TIME += 1;
        }
        
    }else{                                             // Consumer
        printf("I am consumer\n");
        while(1){
            if (cons_sp) continue;
            if (TIME == 0){
                prod_sp = 0;
                cons_sp = 1;
                continue;
            }
            TIME -= 1;
        }
    }
}

int main(){                                            //creating two threads
    int t_c = 2;
    pthread_t ids[t_c];

    for (int h = 0;h<t_c;h++){
        pthread_t id;
        ids[h] = id;
        void *pass = malloc(sizeof(int));
        *((int*)pass) = h;
        pthread_create((ids+h),NULL,thread_f,pass);
    }
    for (int h = 0;h<t_c;h++){
     pthread_join(ids[h],NULL);
    }
    return 0;
}

/*
 * After a few number of producer printed something, he stops,
 * which means both threads've fallen asleep.
*/
