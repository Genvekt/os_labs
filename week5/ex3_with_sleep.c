#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_FULL 10000

int buffer = 0;
pthread_cond_t condition;

void *consumer(void *args)
{
	printf("<Consumer>: thread is starting");
    while(1){
        while(buffer == 0){
            usleep(100);
        }
        buffer -= 1;
    }
    return NULL;

}

void *produser(void *args)
{
	printf("<Produser>: thread is starting");
    while(1){
        usleep(100);
        buffer = buffer + 1000;
        printf("<Produser>: buffer = %d\n", buffer);
        if(buffer >=BUFFER_FULL){
            usleep(100);
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