#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_FULL 10000

int buffer = 0;
pthread_mutex_t mutex;
pthread_cond_t condition;

void *consumer(void *args)
{
	printf("<Consumer>: thread is starting");
    while(1){
        
        while(buffer == 0){
            pthread_cond_wait(&condition, &mutex);
            
        }
        buffer -= 1;
        
    }
    return NULL;

}

void *produser(void *args)
{
	printf("<Produser>: thread is starting");
    while(1){
        usleep(1000);
        buffer = buffer + 7500;
        printf("<Produser>: buffer = %d\n", buffer);
        if(buffer >=BUFFER_FULL){
            pthread_cond_signal(&condition);
            printf("<Produser>: buffer full\n");
        }
        if(buffer <0){
            exit(EXIT_FAILURE);
        }
    
    }
    return NULL;

}

int main(){
    int error = 0;
    pthread_t produser_t, consumer_t;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    error = pthread_create(&produser_t, NULL, produser, NULL);
	if (error != 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

    error = pthread_create(&consumer_t, NULL, consumer, NULL);
	if (error != 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

    pthread_join(produser_t, NULL);
	
	
	return EXIT_SUCCESS;

}