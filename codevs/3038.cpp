#include <stdio.h>
int cnt;
void calc(int num)
{
 if(num==1)return;
 cnt++;
 if(num%2)calc(3*num+1);
 else calc(num/2);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num;
  cnt=0;
  scanf("%d",&num);
  calc(num);
  printf("%d\n",cnt);
 }
 return 0;
}
