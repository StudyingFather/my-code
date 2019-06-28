#include <iostream>
using namespace std;
long long a[100005],sum[400005],add[400005];//线段树要开4倍（划重点）空间，否则你懂的
void pushup(int rt)//将子节点数值合并到根节点
{
 sum[rt]=sum[rt<<1]+sum[(rt<<1)+1];//加法运算优先级高于左移，所以括号不能漏掉
}
void pushdown(int ln,int rn,int rt)//下推标记
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
void build(int l,int r,int rt)//递归建树
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
void update(int L,int R,long long c,int l,int r,int rt)//区间修改
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
long long quary(int L,int R,int l,int r,int rt)//区间查询
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
  char o;
  long long a,b,c;
  cin>>o;
  if(o=='C')
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
