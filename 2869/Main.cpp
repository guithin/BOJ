#include<stdio.h>
int main() {int a,b,v;scanf("%d %d %d",&a,&b,&v);if ((v - a) % (a - b)) printf("%d\n",((v-a)/(a-b))+2);else printf("%d\n",((v-a)/(a-b))+1);}