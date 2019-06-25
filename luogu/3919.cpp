#include <cstdio>
#include <algorithm>
using namespace std;
struct seg
{
 int x,ls,rs;
}s[20000005];
int a[1000005],rt[1000005],cnt;
void build(int&root,int l,int r)
{
 root=++cnt;
 if(l==r)
 {
  s[root].x=a[l];
  return;
 }
 int mid=(l+r)>>1;
 build(s[root].ls,l,mid);
 build(s[root].rs,mid+1,r);
}
void insert(int&root,int pre,int l,int r,int pos,int x)
{
 root=++cnt;
 s[root].x=s[pre].x,s[root].ls=s[pre].ls,s[root].rs=s[pre].rs;
 if(l==r)
 {
  s[root].x=x;
  return;
 }
 int mid=(l+r)>>1;
 if(pos<=mid)insert(s[root].ls,s[pre].ls,l,mid,pos,x);
 else insert(s[root].rs,s[pre].rs,mid+1,r,pos,x);
}
int query(int root,int l,int r,int pos)
{
 if(l==r)return s[root].x;
 int mid=(l+r)>>1;
 if(pos<=mid)return query(s[root].ls,l,mid,pos);
 return query(s[root].rs,mid+1,r,pos);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 build(rt[0],1,n);
 for(int i=1;i<=m;i++)
 {
  int v,op;
  scanf("%d%d",&v,&op);
  if(op==1)
  {
   int pos,x;
   scanf("%d%d",&pos,&x);
   insert(rt[i],rt[v],1,n,pos,x);
  }
  else
  {
   int pos;
   scanf("%d",&pos);
   printf("%d\n",query(rt[v],1,n,pos));
   rt[i]=rt[v];
  }
 }
 return 0;
}