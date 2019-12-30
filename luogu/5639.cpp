#include <cstdio>
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 int lastx=1;
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  if(lastx!=x)ans++,lastx=x;
 }
 printf("%d\n",ans);
 return 0;
}