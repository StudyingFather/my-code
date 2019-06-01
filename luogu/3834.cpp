#include <cstdio>
#include <algorithm>
using namespace std;
struct seg
{
 int ls,rs,sum;
}s[4000005];
int a[200005],b[200005],rt[200005],cnt;
int build(int l,int r)
{
 int root=++cnt;
 if(l==r)return root;
 int mid=(l+r)>>1;
 s[root].ls=build(l,mid);
 s[root].rs=build(mid+1,r);
 return root;
}
int update(int root,int l,int r,int x)
{
 int dir=++cnt;
 s[dir].ls=s[root].ls;
 s[dir].rs=s[root].rs;
 s[dir].sum=s[root].sum+1;
 if(l==r)return dir;
 int mid=(l+r)>>1;
 if(x<=mid)s[dir].ls=update(s[dir].ls,l,mid,x);
 else s[dir].rs=update(s[dir].rs,mid+1,r,x);
 return dir;
}
int query(int u,int v,int l,int r,int x)
{
 int mid=(l+r)>>1,tmp=s[s[v].ls].sum-s[s[u].ls].sum;
 if(l==r)return l;
 if(x<=tmp)return query(s[u].ls,s[v].ls,l,mid,x);
 else return query(s[u].rs,s[v].rs,mid+1,r,x-tmp);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  b[i]=a[i];
 }
 sort(b+1,b+n+1);
 int len=unique(b+1,b+n+1)-b-1;
 rt[0]=build(1,len);
 for(int i=1;i<=n;i++)
  rt[i]=update(rt[i-1],1,len,lower_bound(b+1,b+len+1,a[i])-b);
 for(int i=1;i<=m;i++)
 {
  int l,r,k;
  scanf("%d%d%d",&l,&r,&k);
  printf("%d\n",b[query(rt[l-1],rt[r],1,len,k)]);
 }
 return 0;
}