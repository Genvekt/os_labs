#include <stdio.h>
int main(){
    int n;
    int type;
    printf("Enter a type of figure (0 - triangle; 1 - rectangle; 2 - rhombus) \n");
    scanf("%d", &type);
    printf("Enter a height of a figure: ");
    scanf("%d", &n);

    if(type == 0){
        triangle(n);
    } else if (type == 1){
        rectangle(n);
    } else if (type == 2){
        rhombus(n);
    } else {
        printf("Wrong type, goodbye!");
    }
    
}

void triangle(int n){
    for(int i = n-1; i>=0; i--){
        printf("\n");
        for(int j = i; j>0; j--){
            printf(" ");
        }
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
        printf("*");
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
    }
}
void rectangle (int n){
    for(int i = n; i>0; i--){
        printf("\n");
        for(int j = 2*n-1; j>0;j--){
            printf("*");
        }
    }
}

void rhombus(int n){
    for(int i = n-1; i>=0; i--){
        printf("\n");
        for(int j = i; j>0; j--){
            printf(" ");
        }
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
        printf("*");
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
    }
    for(int i = 1; i<=n-1; i++){
        printf("\n");
        for(int j = i; j>0; j--){
            printf(" ");
        }
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
        printf("*");
        for(int j = n-1-i;j>0; j--){
            printf("*");
        }
    }

}

