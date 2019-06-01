#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MOD 10000019
using namespace std;
int inv[10000025],sum,add,mul=1,all,lastt,ans,n,q,t;
unordered_map<int,int> a,tag;
struct operation
{
 int op,x,val;
}o[1000005];
struct node
{
 int a,b;
}s[105];
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>q;
 inv[1]=1;
 for(int i=2;i<=MOD-1;i++)
  inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
 for(int i=1;i<=q;i++)
 {
  cin>>o[i].op;
  if(o[i].op==1)cin>>o[i].x>>o[i].val;
  else if(o[i].op>=2&&o[i].op<=4)cin>>o[i].val;
  else if(o[i].op==5)cin>>o[i].x;
  o[i].val=(o[i].val%MOD+MOD)%MOD;
 }
 cin>>t;
 for(int i=1;i<=t;i++)
  cin>>s[i].a>>s[i].b;
 for(int i=1;i<=t;i++)
  for(int j=1;j<=q;j++)
  {
   int cur=(s[i].a+j*s[i].b)%q+1,x=o[cur].x,val=o[cur].val,t=(i-1)*q+j;
   if(o[cur].op==1)
   {
    if(tag[x]>lastt)sum-=a[x]*mul+add;
    else sum-=all*mul+add;
    sum=(sum+val)%MOD;
    a[x]=(val-add+MOD)*inv[mul]%MOD;
    tag[x]=t;
   }
   else if(o[cur].op==2)
   {
    sum+=n*val,sum%=MOD;
    add+=val,add%=MOD;
   }
   else if(o[cur].op==3)
   {
    sum*=val,add*=val,mul*=val;
    sum%=MOD,add%=MOD,mul%=MOD;
   }
   else if(o[cur].op==4)
   {
    all=val,lastt=t;
    mul=1,add=0,sum=(val*n)%MOD;
   }
   else if(o[cur].op==5)
   {
    if(tag[x]>lastt)ans+=(a[x]*mul+add)%MOD;
    else ans+=(all*mul+add)%MOD;
    ans%=MOD;
   }
   else if(o[cur].op==6)
   {
    ans+=sum;
    ans%=MOD;
   }
  }
 cout<<(ans%MOD+MOD)%MOD<<endl;
 return 0;
}