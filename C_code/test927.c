#include <stdio.h>

int main(){

    char name[10];
    fgets(name, 10, stdin);

    printf("%s", name);

    return 0;
}