#include <cstdio>
#include <cstring>
struct node
{
 int d,s,t;
}a[1000005];
int r[1000005],d[1000005],n,m;
bool check(int x)
{
 memset(d,0,sizeof(d));
 for(int i=1;i<=x;i++)
 {
  d[a[i].s]+=a[i].d;
  d[a[i].t+1]-=a[i].d;
 }
 int num=0;
 for(int i=1;i<=n;i++)
 {
  num+=d[i];
  if(num>r[i])return false;
 }
 return true;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&r[i]);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].t);
 if(check(m))puts("0");
 else
 {
  puts("-1");
  int l=1,r=m;
  while(l<r)
  {
   int mid=(l+r)>>1;
   if(check(mid))l=mid+1;
   else r=mid;
  }
  printf("%d\n",l);
 }
 return 0;
}