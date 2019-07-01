#include <iostream>
using namespace std;
long long a[100005],sum[400005],add[400005];
void pushup(int rt)
{
 sum[rt]=sum[rt<<1]+sum[(rt<<1)+1];
}
void pushdown(int ln,int rn,int rt)
{
 if(add[rt])
 {
  add[rt<<1]+=add[rt];
  add[(rt<<1)+1]+=add[rt];
  sum[rt<<1]+=add[rt]*ln;
  sum[(rt<<1)+1]+=add[rt]*rn;
  add[rt]=0;
 }
}
void build(int l,int r,int rt)
{
 if(l==r)
 {
  sum[rt]=a[l];
  return;
 }
 int m=(l+r)>>1;
 build(l,m,rt<<1);
 build(m+1,r,(rt<<1)+1);
 pushup(rt);
}
void update(int L,int R,long long c,int l,int r,int rt)
{
 if(L<=l&&r<=R)
 {
  sum[rt]+=c*(r-l+1);
  add[rt]+=c;
  return;
 }
 int m=(l+r)>>1;
 pushdown(m-l+1,r-m,rt);
 if(L<=m)update(L,R,c,l,m,rt<<1);
 if(R>m)update(L,R,c,m+1,r,(rt<<1)+1);
 pushup(rt);
}
long long quary(int L,int R,int l,int r,int rt)
{
 if(L<=l&&r<=R)return sum[rt];
 int m=(l+r)>>1;
 pushdown(m-l+1,r-m,rt);
 long long ans=0;
 if(L<=m)ans+=quary(L,R,l,m,rt<<1);
 if(R>m)ans+=quary(L,R,m+1,r,(rt<<1)+1);
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 int n,q;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 build(1,n,1);
 for(int i=1;i<=q;i++)
 {
  int o;
  long long a,b,c;
  cin>>o;
  if(o==1)
  {
   cin>>a>>b>>c;
   update(a,b,c,1,n,1);
  }
  else
  {
   cin>>a>>b;
   cout<<quary(a,b,1,n,1)<<endl;
  }
 }
 return 0;
}
