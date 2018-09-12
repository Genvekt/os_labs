#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 10, PID = fork();
	if(PID == 0){
		//this is a child process
	printf("Hello from child [%d - %d]\n",PID,n);
	}
	else if(PID > 0){
		//this is a parent process
	printf("Hello from parent [%d - %d]\n",PID,n);
	}
	else{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}