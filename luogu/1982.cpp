#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long a[1000005][3];
int main()
{
 int n,p;
 long long maxn;
 scanf("%d%d",&n,&p);
 p=abs(p);
 int x;
 scanf("%d",&x);
 a[1][1]=x;
 a[1][0]=x;
 maxn=x;
 for(long long i=2;i<=n;i++)
 {
  scanf("%d",&x);
  if(a[i-1][1]>0)a[i][1]=a[i-1][1]+x;
  else a[i][1]=x;
  a[i][0]=max(maxn,a[i][1]);
  maxn=a[i][0];
 }
 int pd=0;
 a[1][2]=a[1][0];
 a[2][2]=2*a[1][0];
 if(a[2][2]>=a[1][2])pd=1;
 for(long long i=3;i<=n;i++)
 {
  if(a[i-1][0]<0)a[i][2]=a[i-1][2];
  else
  {
   a[i][2]=a[i-1][2]+a[i-1][0];
   if(a[i][2]>a[1][2])pd=1;
   a[i][2]%=p;
  }
 }
 if(pd==1)printf("%d\n",(int)a[n][2]%p);
 else printf("%d\n",(int)a[1][2]%p);
 return 0;
}
