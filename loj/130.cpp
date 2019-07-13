#include <iostream>
#include <algorithm>
using namespace std;
long long tr[1000005],n,q;
int lowbit(int x)
{
 return x&(-x);
}
void add(int x,int y)
{
 while(x<=n)
 {
  tr[x]+=y;
  x+=lowbit(x);
 }
}
long long query(int x)
{
 long long ans=0;
 while(x)
 {
  ans+=tr[x];
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
  int x;
  cin>>x;
  add(i,x);
 }
 for(int i=1;i<=q;i++)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int p,x;
   cin>>p>>x;
   add(p,x);
  }
  else
  {
   int l,r;
   cin>>l>>r;
   cout<<query(r)-query(l-1)<<endl;
  }
 }
 return 0;
}