#include <cstdio>
#include <cstring>
int a[15];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  memset(a,0,sizeof(a));
  for(int i=1;i<=5;i++)
  {
   int x;
   scanf("%d",&x);
   a[x]++;
  }
  int ans=0,maxc=0;
  for(int i=1;i<=5;i++)
   if(a[i]>maxc)
   {
    ans=i;
    maxc=a[i];
   }
  printf("%d\n",ans);
 }
 return 0;
}