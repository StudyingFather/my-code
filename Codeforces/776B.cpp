#include <cstdio>
int a[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=2;i<=n+1;i++)
  if(!a[i])
   for(int j=i;(long long)i*j<=n+1;j++)
    a[i*j]=1;
 if(n>=3)puts("2");
 else puts("1");
 for(int i=2;i<=n+1;i++)
  printf("%d ",a[i]+1);
 return 0;
}