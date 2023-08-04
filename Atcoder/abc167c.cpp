// Problem : C - Skill Up
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 998244353
using namespace std;
struct book
{
 int c,a[15];
}b[15];
int res[15],ans=INF;
int main()
{
 int n,m,x;
 cin>>n>>m>>x;
 for(int i=0;i<n;i++)
 {
  cin>>b[i].c;
  for(int j=1;j<=m;j++)
   cin>>b[i].a[j];
 }
 for(int p=0;p<(1<<n);p++)
 {
  int cost=0;
  memset(res,0,sizeof(res));
  for(int i=0;i<n;i++)
  {
   if(p&(1<<i))
   {
    cost+=b[i].c;
    for(int j=1;j<=m;j++)
     res[j]+=b[i].a[j];
   }
  }
  bool flag=true;
  for(int j=1;j<=m;j++)
   flag&=(res[j]>=x);
  if(flag)ans=min(ans,cost);
 }
 if(ans==INF)cout<<-1<<endl;
 else cout<<ans<<endl;
 return 0;
}