#include <cstdio>
#include <algorithm>
using namespace std;
int n,j;
int a[30005],b[30005];
int d1[30005],len1,d2[30005],len2;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  if(a[i]>=d1[len1])d1[++len1]=a[i];
  else
  {
   j=upper_bound(d1+1,d1+len1+1,a[i])-d1;
   d1[j]=a[i];
  }
 for(int i=1;i<=n;i++)
  b[i]=a[n+1-i];
 for(int i=1;i<=n;i++)
  if(b[i]>=d2[len2])d2[++len2]=b[i];
  else
  {
   j=upper_bound(d2+1,d2+len2+1,b[i])-d2;
   d2[j]=b[i];
  }
 int maxn=max(len1,len2);
 printf("%d",n-maxn);
 return 0;
}
