#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int p,t;
}a[10005];
int f[10005],t[10005],cnt=1;
bool cmp(const node&a,const node&b)
{
 return a.p>b.p;
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=k;i++)
 {
  scanf("%d%d",&a[i].p,&a[i].t);
  t[a[i].p]++;
 }
 sort(a+1,a+k+1,cmp);
 for(int i=n;i>=1;i--)
 {
  if(t[i]==0)f[i]=f[i+1]+1;
  else
   for(int j=1;j<=t[i];j++)
   {
    if(f[i+a[cnt].t]>f[i])f[i]=f[i+a[cnt].t];
    cnt++;
   }
 }
 printf("%d\n",f[1]);
 return 0;
}