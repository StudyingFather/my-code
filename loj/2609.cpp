#include <cstdio>
#include <algorithm>
#define MOD 99999997
using namespace std;
struct node
{
 int x,id;
}a[1000005],b[1000005];
int p[1000005],q[1000005],n;
int lowbit(int x)
{
 return x&(-x);
}
int query(int x)
{
 int ans=0;
 while(x)
 {
  ans+=q[x];
  x-=lowbit(x);
 }
 return ans;
}
void update(int x,int y)
{
 while(x<=n)
 {
  q[x]+=y;
  x+=lowbit(x);
 }
}
bool cmp(const node&a,const node&b)
{
 return a.x<b.x;
}
int main()
{
 int ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i].x);
  a[i].id=i;
 }
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&b[i].x);
  b[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 sort(b+1,b+n+1,cmp);
 for(int i=1;i<=n;i++)
  p[a[i].id]=b[i].id;
 for(int i=n;i;i--)
 {
  ans=(ans+query(p[i]-1))%MOD;
  update(p[i],1);
 }
 printf("%d\n",ans);
 return 0;
}