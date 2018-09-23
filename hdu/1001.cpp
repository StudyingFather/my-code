#include <cstdio>
#include <algorithm>
using namespace std;
int f[75005];
int main()
{
 int n,maxn=0;
 while(~scanf("%d",&n))
  if(f[n])printf("%d\n\n",f[n]);
  else
  {
   for(int i=maxn+1;i<=n;i++)
    f[i]=f[i-1]+i;
   printf("%d\n\n",f[n]);
   maxn=n;
  }
 return 0;
}
