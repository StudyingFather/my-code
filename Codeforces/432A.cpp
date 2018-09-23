#include <stdio.h>
int main()
{
 int n,k,cnt=0;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  if(5-num>=k)cnt++;
 }
 printf("%d",cnt/3);
 return 0;
}
