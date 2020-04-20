#include <iostream>
#include <algorithm>
#define MOD 998244353
#define INV2 499122177
using namespace std;
struct seg
{
 long long f,g,s,tag;
}s[800005];
long long p[100005],invp[100005];
void pushup(int rt)
{
 s[rt].s=(s[rt<<1].s+s[rt<<1|1].s+s[rt].f)%MOD;
}
void pushdown(int rt)
{
 int tag=s[rt].tag;
 s[rt<<1].tag+=tag;
 s[rt<<1|1].tag+=tag;
 s[rt<<1].g=(s[rt<<1].g+p[tag]-1)*invp[tag]%MOD;
 s[rt<<1|1].g=(s[rt<<1|1].g+p[tag]-1)*invp[tag]%MOD;
 s[rt].tag=0;
}
void update(int rt,int cl,int cr,int l,int r)
{
 if(cr<l||r<cl)
 {
  s[rt].f=(s[rt].f+s[rt].g)*INV2%MOD;
  pushup(rt);
  return;
 }
 if(l<=cl&&cr<=r)
 {
  s[rt].f=(s[rt].f+1)*INV2%MOD;
  s[rt].g=(s[rt].g+1)*INV2%MOD;
  s[rt].tag++;
  pushup(rt);
  return;
 }
 s[rt].f=s[rt].f*INV2%MOD;
 s[rt].g=s[rt].g*INV2%MOD;
 pushdown(rt);
 int mid=(cl+cr)>>1;
 update(rt<<1,cl,mid,l,r);
 update(rt<<1|1,mid+1,cr,l,r);
 pushup(rt);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 p[0]=invp[0]=1;
 for(int i=1;i<=m;i++)
 {
  p[i]=p[i-1]*2%MOD;
  invp[i]=invp[i-1]*INV2%MOD;
 }
 int cnt=0;
 while(m--)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int l,r;
   cin>>l>>r;
   update(1,1,n,l,r);
   cnt++;
  }
  else cout<<s[1].s*p[cnt]%MOD<<endl;
 }
 return 0;
}