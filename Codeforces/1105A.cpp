#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],n,ans=100000000,rt;
int calc(int x,int t)
{
 if(abs(x-t)<=1)return 0;
 if(x>t)return x-t-1;
 return t-x-1;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 for(int i=1;i<=a[n];i++)
 {
  int res=0;
  for(int j=1;j<=n;j++)
   res+=calc(a[j],i);
  if(res<ans)
  {
   ans=res;
   rt=i;
  }
 }
 printf("%d %d\n",rt,ans);
 return 0;
}