#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000005],b[1000005],sum[1000005],n,q;
int lowbit(int x)
{
 return x&(-x);
}
void update(int x,int y)
{
 long long z=1ll*x*y;
 while(x<=n)
 {
  a[x]+=y;
  b[x]+=z;
  x+=lowbit(x);
 }
}
long long query(int x)
{
 long long tmp=x,res1=0,res2=0;
 while(x)
 {
  res1+=a[x];
  res2+=b[x];
  x-=lowbit(x);
 }
 return sum[tmp]+res1*(tmp+1)-res2;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>q;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  sum[i]=sum[i-1]+x;
 }
 for(int i=1;i<=q;i++)
 {
  int op,l,r,x;
  cin>>op;
  if(op==1)
  {
   cin>>l>>r>>x;
   update(l,x),update(r+1,-x);
  }
  else
  {
   cin>>l>>r;
   cout<<query(r)-query(l-1)<<endl;
  }
 }
 return 0;
}