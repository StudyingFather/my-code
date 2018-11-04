#include <stdio.h>
int t[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&t[i]);
 int cur1=1,cur2=n,t1=0,t2=0;
 while(cur1<=cur2)
 {
  if(t1+t[cur1]<=t2+t[cur2])
  {
   t1+=t[cur1];
   cur1++;
  }
  else
  {
   t2+=t[cur2];
   cur2--;
  }
 }
 printf("%d %d",cur1-1,n-cur1+1);
 return 0;
}
