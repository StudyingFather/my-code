// Problem : B - Easy Linear Programming
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a,b,c,k,ans=0;
 cin>>a>>b>>c>>k;
 ans+=min(a,k);
 k-=min(a,k);
 k-=min(b,k);
 ans-=min(c,k);
 cout<<ans<<endl;
 return 0;
}