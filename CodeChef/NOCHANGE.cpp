#include <iostream>
#include <algorithm>
using namespace std;
int d[1005];
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,p,x=0,y=0;
  bool flag=true;
  cin>>n>>p;
  for(int i=1;i<=n;i++)
   cin>>d[i];
  for(int i=1;i<=n;i++)
   if(p%d[i])
   {
    cout<<"YES ";
    for(int j=1;j<=n;j++)
     if(i==j)cout<<p/d[i]+1<<' ';
     else cout<<0<<' ';
    flag=false;
    break;
   }
  if(flag)
  {
   for(int i=1;i<=n;i++)
   {
    for(int j=i+1;j<=n;j++)
     if(gcd(d[i],d[j])!=d[i])
     {
      x=i,y=j,p-=d[j];
      break;
     }
    if(x)break;
   }
   if(x)
   {
    cout<<"YES ";
    for(int i=1;i<=n;i++)
     if(i==x)cout<<p/d[i]+1<<' ';
     else if(i==y)cout<<1<<' ';
     else cout<<0<<' ';
   }
   else cout<<"NO";
  }
  cout<<endl;
 }
 return 0;
}