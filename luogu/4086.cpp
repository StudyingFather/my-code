#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mins[100005],a[100005],post[100005],re[100005],cnt,n;
long double ans;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 mins[n]=post[n]=a[n];
 for(int i=n-1;i>=1;i--)
 {
  mins[i]=min(mins[i+1],a[i]);
  post[i]=post[i+1]+a[i];
 }
 for(int k=1;k<=n-2;k++)
 {
  long double cur=((long double)post[k+1]-mins[k+1])/(n-k-1);
  if(ans<cur)
  {
   ans=cur;
   memset(re,0,sizeof(re));
   re[cnt=1]=k;
  }
  else if(ans==cur)re[++cnt]=k;
 }
 for(int i=1;i<=cnt;i++)
  printf("%d\n",re[i]);
 return 0;
}
