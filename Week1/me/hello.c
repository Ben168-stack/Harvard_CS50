#include <stdio.h>
// Program Thats asks for you name and greets your name in C programming
int main() {
    char name[50];

    printf("Whats your name? ");
    scanf("%49s", name);
    printf("hello, %s!\n", name);  
    
    return 0;
}