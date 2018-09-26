#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int  signal_here = 1;
void  handler(int sig)
{
     signal_here = 0;
     
}

int main(){
     signal(SIGINT, handler);
     while(signal_here){}
     printf("Ctrl-C was cought!\n");
     return EXIT_SUCCESS;

}