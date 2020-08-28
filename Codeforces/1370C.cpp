// Problem : C. Number Game
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int calc(int x)
{
 int cx=x;
 while(cx%2==0)
  cx/=2;
 int cnt=0;
 for(int i=3;i*i<=x;i++)
  while(cx%i==0)
   cx/=i,cnt++;
 if(cx!=1)cnt++;
 return cnt;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  if(n==1)cout<<"FastestFinger"<<endl;
  else if(n==2||n%2)cout<<"Ashishgup"<<endl;
  else
  {
   int cnt=calc(n);
   if(cnt==0)cout<<"FastestFinger"<<endl;
   else if(n%4==0||cnt>=2)cout<<"Ashishgup"<<endl;
   else cout<<"FastestFinger"<<endl;
  }
 }
}