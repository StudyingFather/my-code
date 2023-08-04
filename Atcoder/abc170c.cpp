
// Problem : C - Forbidden List
// Contest : AtCoder - AtCoder Beginner Contest 170
// URL : https://atcoder.jp/contests/abc170/tasks/abc170_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int t[205];
int main()
{
 int x,n,d=200,ans=0;
 cin>>x>>n;
 for(int i=1;i<=n;i++)
 {
  int p;
  cin>>p;
  t[p]=1;
 }
 for(int i=0;i<=200;i++)
  if(!t[i]&&abs(i-x)<d)
  {
   ans=i;
   d=abs(i-x);
  }
 cout<<ans<<endl;
 return 0;
}