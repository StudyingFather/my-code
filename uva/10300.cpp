#include <stdio.h>
int main()
{
 int n,m,a,b,c;
 scanf("%d",&n);
 while(n--)
 {
  scanf("%d",&m);
  int ans=0;
  for(int i=1;i<=m;i++)
  {
   scanf("%d%d%d",&a,&b,&c);
   int d=a*c;
   ans+=d;
  }
  printf("%d\n",ans);
 }
 return 0;
}
