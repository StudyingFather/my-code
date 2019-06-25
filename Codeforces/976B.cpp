#include <iostream>
using namespace std;
long long n,m,k;
int main()
{
 cin>>n>>m>>k;
 long long x,y;
 if(k<=n-1)cout<<k+1<<' '<<1;
 else if(k>=m*n-1)cout<<1<<' '<<2;
 else
 {
  x=n-(k-n+1)/(m-1)+1;
  y=(k-n+1)%(m-1);
  if(y!=0)x--;
  if(x%2==0)
  {
   if(y==0)y=m;
   else y++;
  }
  else
  {
   if(y==0)y=2;
   else y=m-y+1;
  }
  cout<<x<<' '<<y;
 }
 return 0;
}
