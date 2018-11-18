#include <stdio.h>
int res,cnt;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  if(res==num)cnt++;
  else if(cnt>0)cnt--;
  else res=num;
 }
 printf("%d\n",res);
 return 0;
}
