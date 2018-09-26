#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
pid_t secondCildID;
int status;
int main(){

    int io[2];
    int error = pipe(io);
    if(error<0){
        return EXIT_FAILURE;
    }

    //create first child
    pid_t pid = fork();

    if(pid <0){
        return EXIT_FAILURE;
    }
    else if(pid == 0){
        //it is first child process
        close(io[1]); //close output of first child
        read(io[0],&secondCildID,sizeof(secondCildID)); //read second child pid
        printf("<CHILD 1>: got %d fron parent! \n",secondCildID);
        printf("<CHILD 1>: 10 sec to kill second child! \n");
        sleep(10);
        printf("<CHILD 1>: KILLING \n");
        kill (secondCildID, SIGSTOP);
        exit(EXIT_SUCCESS);

        
    }
    else{
        //it is parent
        printf("<PARENT>: first child is created! \n");
       pid = fork();
       if(pid <0){
            return EXIT_FAILURE;
        }
        else if(pid == 0){
            //it is second child process
            close(io[0]);
            close(io[1]); //close in and out of second child

            while(1){
                printf("<CHILD 2>: I'm alive! \n");
                sleep(1);
            }
            exit(EXIT_SUCCESS);
        
        }
        else{
            //it is still parent
            printf("<PARENT>: second child is created! \n");
            close(io[0]); //close input of parent
             printf("<PARENT>: sending %d to first child! \n",pid);
            write(io[1],&pid,sizeof(pid)); //send pid of second child to the first child
            printf("<PARENT>: I'm waiting for second child! \n");
            do{
                if(error = waitpid(pid, &status, WUNTRACED) == -1){
                    return EXIT_FAILURE;
                }
                else if(error == 0){
                    printf("<PARENT>: I'm waiting for second child! \n");
                sleep(1);
                }
                else{
                     printf("<PARENT>: second child's status changed: %d! \n",status);
                }
            } while(error == 0);
        }
    }
    return  EXIT_SUCCESS;
}