#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],n,q;
int lowbit(int x)
{
 return x&(-x);
}
void add(int x,long long y)
{
 while(x<=n)
 {
  a[x]+=y;
  x+=lowbit(x);
 }
}
long long query(int x)
{
 long long ans=0;
 while(x)
 {
  ans+=a[x];
  x-=lowbit(x);
 }
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>q;
 for(int i=1;i<=n;i++)
 {
  long long x;
  cin>>x;
  add(i,x);
  add(i+1,-x);
 }
 for(int i=1;i<=q;i++)
 {
  long long op,x,y,k;
  cin>>op;
  if(op==1)
  {
   cin>>x>>y>>k;
   add(x,k),add(y+1,-k);
  }
  else
  {
   cin>>x;
   cout<<query(x)<<endl;
  }
 }
 return 0;
}