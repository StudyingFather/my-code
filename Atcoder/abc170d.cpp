// Problem : D - Not Divisible
// Contest : AtCoder - AtCoder Beginner Contest 170
// URL : https://atcoder.jp/contests/abc170/tasks/abc170_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
int a[200005],f[1000005],t[1000005];
int main()
{
 ios::sync_with_stdio(false);
 int n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  t[a[i]]++;
 }
 sort(a+1,a+n+1);
 for(int i=1;i<=n;i++)
 {
  if(!f[a[i]])
  {
   if(t[a[i]]==1)ans++;
   for(int j=a[i];j<=1000000;j+=a[i])
    f[j]=1;
  }
 }
 cout<<ans<<endl;
 return 0;
}