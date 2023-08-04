// Problem : B - Mix Juice
// Contest : AtCoder - AtCoder Beginner Contest 171
// URL : https://atcoder.jp/contests/abc171/tasks/abc171_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
int p[1005];
int main()
{
 int n,k;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>p[i];
 sort(p+1,p+n+1);
 int sum=0;
 for(int i=1;i<=k;i++)
  sum+=p[i];
 cout<<sum<<endl;
 return 0;
}
