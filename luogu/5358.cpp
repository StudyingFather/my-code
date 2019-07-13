#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MOD 10000019
using namespace std;
long long inv[10000025],sum,add,mul=1,all,lastt,ans,n,q,t;
unordered_map<long long,long long> a,tag;
struct operation
{
 long long op,x,val;
}o[1000005];
struct node
{
 long long a,b;
}s[105];
inline void calc_inv()
{
 inv[1]=1;
 for(int i=2;i<=MOD-1;i++)
  inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
}
inline void upd_single(long long x,long long val,long long t)
{
 if(tag[x]>lastt)sum-=a[x]*mul+add;
 else sum-=all*mul+add;
 sum=(sum+val)%MOD;
 a[x]=(val-add+MOD)*inv[mul]%MOD;
 tag[x]=t;
}
inline void upd_all(long long val,long long t)
{
 all=val,lastt=t;
 a.clear(),tag.clear();
 mul=1,add=0,sum=(val*n)%MOD;
}
inline void add_all(long long val)
{
 sum+=n*val,sum%=MOD;
 add+=val,add%=MOD;
}
inline void mul_all(long long val)
{
 sum*=val,add*=val,mul*=val;
 sum%=MOD,add%=MOD,mul%=MOD;
}
inline int query_single(long long x)
{
 if(tag[x]>lastt)return (a[x]*mul+add)%MOD;
 else return (all*mul+add)%MOD;
}
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0);
 cin>>n>>q;
 calc_inv();
 for(int i=1;i<=q;i++)
 {
  cin>>o[i].op;
  if(o[i].op==1)cin>>o[i].x>>o[i].val;
  else if(o[i].op>=2&&o[i].op<=4)cin>>o[i].val;
  else if(o[i].op==5)cin>>o[i].x;
  o[i].val%=MOD;
  if(o[i].val<0)o[i].val+=MOD;
 }
 cin>>t;
 for(int i=1;i<=t;i++)
  cin>>s[i].a>>s[i].b;
 for(int i=1;i<=t;i++)
  for(int j=1;j<=q;j++)
  {
   int cur=(s[i].a+j*s[i].b)%q+1;
   if(o[cur].op==1)upd_single(o[cur].x,o[cur].val,(i-1)*q+j);
   else if(o[cur].op==2)add_all(o[cur].val);
   else if(o[cur].op==3)mul_all(o[cur].val);
   else if(o[cur].op==4)upd_all(o[cur].val,(i-1)*q+j);
   else if(o[cur].op==5)ans+=query_single(o[cur].x),ans%=MOD;
   else if(o[cur].op==6)ans+=sum,ans%=MOD;
  }
 cout<<(ans%MOD+MOD)%MOD<<endl;
 return 0;
}