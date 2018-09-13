#include<stdio.h>

int main(){
    char str[3][15]={"Vaporeon", "Jolteon", "Flareon"};
    int i;
    printf("%s\n", str[((unsigned long long)&i)%3]);
    return 0;
}