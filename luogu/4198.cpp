#include <cstdio>
#include <algorithm>
using namespace std;
int ans[400005];
double seg[400005];
int query(int root,int l,int r,double k)
{
 int mid=(l+r)>>1;
 if(k>=seg[root])return 0;
 else if(l==r)return 1;
 else if(k<seg[root<<1])return query(root<<1,l,mid,k)+ans[root]-ans[root<<1];
 else return query(root<<1|1,mid+1,r,k);
}
void update(int root,int l,int r,int p,double k)
{
 if(l==p&&r==p)
 {
  ans[root]=1;
  seg[root]=k;
  return;
 }
 int mid=(l+r)>>1;
 if(p<=mid)update(root<<1,l,mid,p,k);
 else update(root<<1|1,mid+1,r,p,k);
 seg[root]=max(seg[root<<1],seg[root<<1|1]);
 ans[root]=ans[root<<1]+query(root<<1|1,mid+1,r,seg[root<<1]);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  update(1,1,n,x,(double)y/x);
  printf("%d\n",ans[1]);
 }
 return 0;
}