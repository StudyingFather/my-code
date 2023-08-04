// Problem : D - Min Max Repetition
// Contest : AtCoder - AtCoder Grand Contest 020
// URL : https://atcoder.jp/contests/agc020/tasks/agc020_d
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cmath>
#include <iostream>
using namespace std;
int a,b,c,d,k;
int ra,rb;
bool check(int pos)
{
 ra=a-pos/(k+1)*k-pos%(k+1);
 rb=b-pos/(k+1);
 return 1ll*ra*k>=rb;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  cin>>a>>b>>c>>d;
  k=max(ceil(1.0*a/(b+1)),ceil(1.0*b/(a+1)));
  int l=0,r=a+b;
  while(l<r)
  {
   int mid=(l+r)>>1;
   if(check(mid))
    l=mid+1;
   else
    r=mid;
  }
  check(l);
  r=l+1+rb-ra*k;
  for(int i=c;i<=d;i++)
   if(i<=l)
   {
    if(i%(k+1))cout<<'A';
    else cout<<'B';
   }
   else
   {
    if((i-r)%(k+1))cout<<'B';
    else cout<<'A';
   }
  cout<<endl;
 }
 return 0;
}