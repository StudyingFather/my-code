#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,f[5005],a[5005],ans,s[25],arr=1;
int main()
{
 int n=1;
 while(~scanf("%d",&a[n]))
  n++;
 n--;
 for(int i=1;i<=n;i++)
  f[i]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   if(a[j]>a[i])f[i]=max(f[j]+1,f[i]);
 for(int i=1;i<=n;i++)
  ans=max(f[i],ans);
 printf("%d\n",ans);
 s[1]=a[1];
 for(int i=2;i<=n;i++)
 {
  int minh=50000,used=0;
  for(int j=1;j<=arr;j++)
   if(s[j]>a[i])
    if(s[j]<minh)
    {
     used=j;
     minh=s[j];
    }
  if(used==0)
  {
   arr++;
   s[arr]=a[i];
  }
  else s[used]=a[i];
 }
 printf("%d",arr);
 return 0;
}
