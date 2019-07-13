#include <cstdio>
#include <algorithm>
using namespace std;
struct prob
{
 int l,r,id;
}p[500005];
int a[500005],t[1000005],ans[500005],bit[500005],n,m;
bool cmp(const prob&a,const prob&b)
{
 return a.r<b.r;
}
int lowbit(int x)
{
 return x&(-x);
}
void update(int x,int y)
{
 while(x<=n)
 {
  bit[x]+=y;
  x+=lowbit(x);
 }
}
int query(int x)
{
 int ans=0;
 while(x)
 {
  ans+=bit[x];
  x-=lowbit(x);
 }
 return ans;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 scanf("%d",&m);
 for(int i=1;i<=m;i++)
 {
  scanf("%d%d",&p[i].l,&p[i].r);
  p[i].id=i;
 }
 sort(p+1,p+m+1,cmp);
 int pos=1;
 for(int i=1;i<=m;i++)
 {
  while(pos<=p[i].r)
  {
   if(t[a[pos]])update(t[a[pos]],-1);
   update(pos,1);
   t[a[pos]]=pos;
   pos++;
  }
  ans[p[i].id]=query(p[i].r)-query(p[i].l-1);
 }
 for(int i=1;i<=m;i++)
  printf("%d\n",ans[i]);
 return 0;
}