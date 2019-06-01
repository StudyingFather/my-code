#include <cstdio>
#include <algorithm>
using namespace std;
struct seg
{
 int maxf,len,maxl,maxr,tag;
}s[400005];
void build(int root,int l,int r)
{
 s[root].maxf=s[root].len=s[root].maxl=s[root].maxr=r-l+1;
 s[root].tag=-1;
 if(l==r)return;
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
}
void pushup(int root)
{
 if(s[root<<1].maxf==s[root<<1].len)s[root].maxl=s[root<<1].len+s[root<<1|1].maxl;
 else s[root].maxl=s[root<<1].maxl;
 if(s[root<<1|1].maxf==s[root<<1|1].len)s[root].maxr=s[root<<1|1].len+s[root<<1].maxr;
 else s[root].maxr=s[root<<1|1].maxr;
 s[root].maxf=max(s[root<<1].maxr+s[root<<1|1].maxl,max(s[root<<1].maxf,s[root<<1|1].maxf));
}
void pushdown(int root)
{
 if(s[root].tag==1)
 {
  s[root<<1].tag=s[root<<1|1].tag=1;
  s[root<<1].maxf=s[root<<1].maxl=s[root<<1].maxr=0;
  s[root<<1|1].maxf=s[root<<1|1].maxl=s[root<<1|1].maxr=0;
 }
 else if(!s[root].tag)
 {
  s[root<<1].tag=s[root<<1|1].tag=0;
  s[root<<1].maxf=s[root<<1].maxl=s[root<<1].maxr=s[root<<1].len;
  s[root<<1|1].maxf=s[root<<1|1].maxl=s[root<<1|1].maxr=s[root<<1|1].len;
 }
 s[root].tag=-1;
}
int query(int root,int l,int r,int x)
{
 pushdown(root);
 if(l==r)return l;
 int mid=(l+r)>>1;
 if(s[root<<1].maxf>=x)return query(root<<1,l,mid,x);
 else if(s[root<<1].maxr+s[root<<1|1].maxl>=x)return mid-s[root<<1].maxr+1;
 else return query(root<<1|1,mid+1,r,x);
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 pushdown(root);
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  if(x==1)s[root].maxf=s[root].maxl=s[root].maxr=0;
  else s[root].maxf=s[root].maxl=s[root].maxr=s[root].len;
  s[root].tag=x;
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 build(1,1,n);
 for(int i=1;i<=m;i++)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int x;
   scanf("%d",&x);
   if(s[1].maxf>=x)
   {
    int l=query(1,1,n,x);
    printf("%d\n",l);
    update(1,1,n,l,l+x-1,1);
   }
   else puts("0");
  }
  else
  {
   int x,y;
   scanf("%d%d",&x,&y);
   update(1,1,n,x,x+y-1,0);
  }
 }
 return 0;
}