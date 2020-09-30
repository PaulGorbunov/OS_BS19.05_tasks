#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* __realloc__(int *p, int old_size,int new_size) {
    if (p == NULL) {                                          // If ptr is NULL, the call is equivalent to malloc(size)
        p = malloc(new_size);
        return p;
    }else if ((new_size == 0)||(old_size==0)) {
        free(p);                                             // If size is equal to zero, the call is equivalent to free(ptr)
        return p;
    }else if(old_size >= new_size){
        return p;                                           // If old_size >= new_size no need in reallocating memory
                                                            // just don't look at the part of the memory you don't want to use anymore
    }else {
        int *lap = malloc(new_size);                      // malloc new_size
        if(lap){
            for (int i=0;i<new_size;i++){
                lap[i] = p[i];                             // copying the one-room list to the multi-room one
            } 
                                                           // not using memcpy, as memory areas may overlap
                                                           // which will lead to the wrong copying
            free(p); 
        }
        return lap;
    }
    
}


int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));    //Filling
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;                        //Filling
		
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i] );            //Filling
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = __realloc__(a1,n1,n2);   //Filling            USING OWN WRITTEN __realloc__

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if(n2 > n1) {
        for (int i = n1; i < n2; i++) {
            a1[i] = 0;                                       //more Filling
        }
    } 
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);       //still Filling
	}
	printf("\n");
	
	//Done with array now, done with program :D
	//cool Filling time
	return 0;
}
