// Problem : E - Red Scarf
// Contest : AtCoder - AtCoder Beginner Contest 171
// URL : https://atcoder.jp/contests/abc171/tasks/abc171_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int n,a[200005];
int main()
{
 int n,sum=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  sum^=a[i];
 }
 for(int i=1;i<=n;i++)
  cout<<(sum^a[i])<<' ';
 return 0;
}
