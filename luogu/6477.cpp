// Problem : P6477 [NOI Online #2 提高组]子序列问题（民间数据）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6477
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int a[1000005],b[1000005],c[1000005],last[1000005];
struct seg
{
 long long sum,sum2,tag;
}s[4000005];
void pushup(int root)
{
 s[root].sum=(s[root<<1].sum+s[root<<1|1].sum)%MOD;
 s[root].sum2=(s[root<<1].sum2+s[root<<1|1].sum2)%MOD;
}
void pushdown(int root,int l,int r)
{
 long long tag=s[root].tag;
 int ls=root<<1,rs=root<<1|1,mid=(l+r)>>1;
 s[ls].sum2=(s[ls].sum2+2*s[ls].sum*tag+(mid-l+1)*tag%MOD*tag)%MOD;
 s[rs].sum2=(s[rs].sum2+2*s[rs].sum*tag+(r-mid)*tag%MOD*tag)%MOD;
 s[ls].sum=(s[ls].sum+(mid-l+1)*tag)%MOD;
 s[rs].sum=(s[rs].sum+(r-mid)*tag)%MOD;
 s[ls].tag+=tag;
 s[rs].tag+=tag;
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r)
{
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  s[root].sum2=(s[root].sum2+2*s[root].sum+(cr-cl+1))%MOD;
  s[root].sum=(s[root].sum+(cr-cl+1))%MOD;
  s[root].tag++;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r);
 update(root<<1|1,mid+1,cr,l,r);
 pushup(root);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>b[i];
  c[i]=b[i];
 }
 sort(b+1,b+n+1);
 int l=unique(b+1,b+n+1)-b-1;
 for(int i=1;i<=n;i++)
 {
  a[i]=lower_bound(b+1,b+l+1,c[i])-b;
  update(1,1,n,last[a[i]]+1,i);
  ans=(ans+s[1].sum2)%MOD;
  last[a[i]]=i;
 }
 cout<<ans<<endl;
 return 0;
}