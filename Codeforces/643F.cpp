#include <iostream>
#include <vector>
using namespace std;
typedef unsigned ui;
ui res[205];
ui gcd(ui x,ui y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n,p,q;
 ui ans=0;
 cin>>n>>p>>q;
 p=min(n-1,p);
 for(int k=0;k<=p;k++)
 {
  res[k]=1;
  vector<ui> r1,r2;
  for(int x=n;x>n-k;x--)
   r1.push_back(x);
  for(int y=k;y;y--)
   r2.push_back(y);
  for(auto&x:r1)
   for(auto&y:r2)
   {
    ui g=gcd(x,y);
    x/=g,y/=g;
   }
  for(auto x:r1)
   res[k]*=x;
 }
 for(int i=1;i<=q;i++)
 {
  ui num=0,tmp=1;
  for(int j=0;j<=p;j++)
   num+=res[j]*tmp,tmp*=i;
  ans^=num*i;
 }
 cout<<ans<<endl;
 return 0;
}