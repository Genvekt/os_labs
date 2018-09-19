#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* taskToDo(){
    printf("\n     I am a thread. ID:%d\n",pthread_self());
    printf("     Closing thread with ID:%d...\n",pthread_self());
    pthread_exit(NULL);
    return NULL;
}

int main(){
    int n = 0;
    printf("How many threads you need to create?\n");
    scanf("%d",&n);
    pthread_t threads[n];

    for(int i = 0; i<n; i++){
        int error = pthread_create(&(threads[i]), NULL, &taskToDo, NULL);
        if(error == 0){
            printf("\nThread #%d was successfully created\nIts ID:%d\n",i+1,threads[i]);
        }
        else{
            printf("\n Failed to create thread \n Reason: [%s] \n",i+1,strerror(error));
            return -1;
        }
        pthread_join(threads[i], NULL);
    }
    return 0;
}