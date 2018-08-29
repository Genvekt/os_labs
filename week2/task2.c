#include <string.h>
#include <stdio.h>
int main(){
    char line[1000];

    printf("Enter a line: ");
    scanf("%[^\n]", line);
    printf("Reversed line: ");
    for(int i = strlen(line)-1; i>=0;i--){
        printf("%c", line[i] );
    }
    printf("\n");

}