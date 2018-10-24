#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
int main(){
	DIR *mydir = opendir("tmp");
	if(mydir == NULL) {
		return 1;
	}
	struct stat fileStat;
	struct dirent *dp;
	char dir_name[100];
	strcpy(dir_name, "tmp/");
	while((dp = readdir(mydir))!=NULL){
		strcat(dir_name,dp->d_name);
		stat(dir_name,&fileStat);
		if(fileStat.st_nlink>1){
			printf("%s has links to it! Link files:\n",dp->d_name);
			struct dirent *link;
			DIR *mydir2 = opendir("tmp");
			while((link = readdir(mydir2))!=NULL){
				if((link->d_ino == dp->d_ino) &(strcmp(link->d_name,dp->d_name)!=0)){
					printf("%s ",link->d_name);
				}
			}
			printf("\n");
		}
		else printf("%s has no links\n", dp->d_name);
		strcpy(dir_name,"tmp/");
	}
	return 0;
}
