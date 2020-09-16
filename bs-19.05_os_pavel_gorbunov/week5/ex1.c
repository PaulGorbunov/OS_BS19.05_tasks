#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

void *thread_f(void *varg){
    pthread_mutex_lock(&lock);                              // for the fixed version using lock to force into the order
    printf("Thread number %d is running.\n",*((int*)varg));
    pthread_mutex_unlock(&lock);                            // for fixed version releasing lock
}

int main(){
    int t_c = 3;
    pthread_t ids[t_c];
    if (pthread_mutex_init(&lock,NULL) != 0){              // initiating lock for the fixed version          
        printf("bad\n");
        return 0;
    }
    for (int h = 0;h<t_c;h++){
        pthread_t id;
        ids[h] = id;
        void *pass = malloc(sizeof(int));                       
        *((int*)pass) = h;                                       
        pthread_create((ids+h),NULL,thread_f,pass);              
        printf("Created thread %d.\n",h);
    }
    for (int h = 0;h<t_c;h++){
     pthread_join(ids[h],NULL);
    }
    pthread_mutex_destroy(&lock);                          // destroying lock for the fixed version
    return 0;
}

/*
 * 
 * For the unfixed version output:
Created thread 0.
Created thread 1.
Thread number 1 is running.
Thread number 0 is running.
Created thread 2.
Thread number 2 is running.
 *
 * Output fixed version:
 Created thread 0.
Thread number 0 is running.
Created thread 1.
Thread number 1 is running.
Created thread 2.
Thread number 2 is running.
 */
