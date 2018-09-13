#include<stdio.h>

int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  long long ans=a*b*c;
  int arr[15]={0};
  while(ans){
    arr[ans%10]++;
    ans/=10;
  }
  for(int i=0;i<=9;i++){
    printf("%d\n", arr[i]);
  }
  return 0;
}
