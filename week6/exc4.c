#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int  signal_kill = 1,signal_stop = 1,signal_usr1 = 1;
void  handlerKILL(int sig)
{
     signal_kill = 0;
     
}

void  handlerSTOP(int sig)
{
     signal_stop = 0;
     
}

void  handlerUSR1(int sig)
{
     signal_usr1 = 0;
     
}


int main(){
     signal(SIGKILL, handlerKILL);
     signal(SIGSTOP, handlerSTOP);
     signal(SIGUSR1, handlerUSR1);

     while(signal_kill & signal_stop & signal_usr1){}
     if(!signal_kill){printf("kill signal was cought!\n");}
     else if(!signal_stop){printf("stop signal was cought!\n");}
     else if(!signal_usr1){printf("usr1 signal was cought!\n");}
     return EXIT_SUCCESS;

}