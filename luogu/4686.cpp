#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int pos,id,type;
 bool operator<(const node&a)const
 {
  return pos<a.pos;
 }
}a[2000005];
struct seg
{
 int l,r;
}s[2000005];
int siz[2000005],vis[2000005],cnt,cntl,ans,n,m;
bool cmp(int a,int b)
{
 return a>b;
}
void add(int pos,int id,int type)
{
 a[++cnt].pos=pos;
 a[cnt].id=id;
 a[cnt].type=type;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&s[i].l,&s[i].r);
  add(s[i].l,i,0);
  add(s[i].r,i,1);
 }
 sort(a+1,a+cnt+1);
 int cur=1;
 while(cur!=cnt+1)
 {
  vis[cur]=1;
  ans++;
  if(a[cur].type)cur=lower_bound(a+1,a+cnt+1,(node){s[a[cur].id].l+1,0,0})-a;
  else cur=lower_bound(a+1,a+cnt+1,(node){s[a[cur].id].r+1,0,0})-a;
 }
 vis[cur]=1;
 for(int i=1;i<=cnt;i++)
  if(!vis[i])
  {
   cur=i,cntl++;
   while(!vis[cur])
   {
    vis[cur]=1;
    siz[cntl]++;
    if(a[cur].type)cur=lower_bound(a+1,a+cnt+1,(node){s[a[cur].id].l+1,0,0})-a;
    else cur=lower_bound(a+1,a+cnt+1,(node){s[a[cur].id].r+1,0,0})-a;
   }
  }
 sort(siz+1,siz+cntl+1,cmp);
 for(int i=1;i<=cntl&&m;i++,m--)
  ans+=2+siz[i];
 if(m)
 {
  if(m&1)m--,ans++;
  ans+=2*m;
 }
 printf("%d\n",ans);
 return 0;
}