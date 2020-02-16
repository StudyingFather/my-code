#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,k,l,r;
int f[500005][25],a[500005];
struct node
{
 int l,r1,r2,pos,res;
 bool operator<(const node&a)const
 {
  return res<a.res;
 }
};
priority_queue<node> q;
void init()
{
 for(int i=1;i<=n;i++)
  f[i][0]=i;
 for(int j=1;(1<<j)<=n;j++)
  for(int i=1;i+(1<<(j-1))-1<=n;i++)
  {
   int x=f[i][j-1],y=f[i+(1<<(j-1))][j-1];
   if(a[x]>a[y])f[i][j]=x;
   else f[i][j]=y;
  }
}
int query(int l,int r)
{
 int len=r-l+1;
 int k=log2(len);
 int x=f[l][k],y=f[r-(1<<k)+1][k];
 if(a[x]>a[y])return x;
 return y;
}
int main()
{
 cin>>n>>k>>l>>r;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  a[i]+=a[i-1];
 }
 init();
 for(int i=1;i<=n-l+1;i++)
 {
  int lpos=i+l-1,rpos=min(n,i+r-1),pos=query(lpos,rpos);
  int res=a[pos]-a[i-1];
  q.push({i,lpos,rpos,pos,res});
 }
 long long ans=0;
 while(k--)
 {
  int l=q.top().l,r1=q.top().r1,r2=q.top().r2,pos=q.top().pos,res=q.top().res;
  q.pop();
  ans+=res;
  if(pos-1>=r1)
  {
   int np=query(r1,pos-1);
   int res=a[np]-a[l-1];
   q.push({l,r1,pos-1,np,res});
  }
  if(pos+1<=r2)
  {
   int np=query(pos+1,r2);
   int res=a[np]-a[l-1];
   q.push({l,pos+1,r2,np,res});
  }
 }
 cout<<ans<<endl;
 return 0;
}