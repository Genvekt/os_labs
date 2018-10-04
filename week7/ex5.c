#include <stdio.h>

int main() {
    char **s;
    char foo[] = "Hello World";

    //s = foo  - s is char**, foo is char* -> segmentation foult
    s = &foo;
    printf("s is %s\n",s);

    //s[0] = foo[0] - s has no memory allocated, it just pointer to one char
    //we can give just adress, not value
    //foo is the pointer to the first char of string
    //so to give s an adress of foo:
    s = &foo;
    //but to see 1 char we must printf char, not string
    printf("s[0] is %c\n",*s);
    return(0); 

}