// Problem : D - Teleporter
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
int a[200005],vis[200005];
int main()
{
 ios::sync_with_stdio(false);
 memset(vis,-1,sizeof(vis));
 int n;
 long long k;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 int cur=1;
 for(int i=0;i<=k;i++)
 {
  if(vis[cur]==-1)vis[cur]=i;
  else
  {
   int r=i-vis[cur];
   k=(k-i)%r;
   while(k--)
    cur=a[cur];
   break;
  }
  if(i<k)cur=a[cur];
 }
 cout<<cur<<endl;
 return 0;
}