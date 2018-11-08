#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// to find out if there is -a option
int fileMode(int argc, char *argv[]){
    for(int i = 1; i<argc;i++){
        if(strcmp(argv[i],"-a") == 0){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
   mode_t mode;
   int fileNum, initial;
   char buffer[500];
   ssize_t dataLen, writtenLen;

   //define mode and number of files to open
   if(fileMode){
       mode = O_APPEND;
       fileNum = argc-2;
       initial = 2;
   }
   else{
       mode = O_RDONLY;
       fileNum = argc-1;
       initial = 1;
   }

   int files[fileNum];

   //open files to read:
   for(int i = initial; i<argc; i++){
       files[i-initial] = open(argv[i],mode);
   }

   //reading portion of data
   while((dataLen = read (STDIN_FILENO, buffer, 500)) != 0){
       //write this data to stdout
       write(STDOUT_FILENO, buffer, dataLen);
       //write this data to all files
       for(int i = initial; i<argc; i++){
            writtenLen = write(argv[i],buffer,dataLen);
        }
   }
  

    for(int i = initial; i<argc; i++){
       close(files[i-initial]);
   }
   


}