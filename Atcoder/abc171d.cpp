// Problem : D - Replacing
// Contest : AtCoder - AtCoder Beginner Contest 171
// URL : https://atcoder.jp/contests/abc171/tasks/abc171_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int t[100005];
int main()
{
 int n;
 long long sum=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  t[x]++;
  sum+=x;
 }
 int q;
 cin>>q;
 while(q--)
 {
  int x,y;
  cin>>x>>y;
  sum+=t[x]*(y-x);
  cout<<sum<<endl;
  t[y]+=t[x],t[x]=0;
 }
 return 0;
}
