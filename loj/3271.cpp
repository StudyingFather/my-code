// Problem : #3271. 「JOISC 2020 Day1」建筑装饰 4
// Contest : LibreOJ
// URL : https://loj.ac/problem/3271
// Memory Limit : 512 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define INF 1e9
using namespace std;
int a[1000005][2],f[1000005][2],g[1000005][2];
char res[1000005];
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 n<<=1;
 for(int k=0;k<2;k++)
  for(int i=1;i<=n;i++)
   cin>>a[i][k];
 for(int i=1;i<=n;i++)
  for(int j=0;j<2;j++)
  {
   f[i][j]=-INF,g[i][j]=INF;
   for(int k=0;k<2;k++)
    if(a[i][j]>=a[i-1][k])
    {
     f[i][j]=max(f[i][j],f[i-1][k]+j);
     g[i][j]=min(g[i][j],g[i-1][k]+j);
    }
  }
 int rem=n>>1,p=INF;
 for(int i=n;i;i--)
 {
  bool flag=false;
  for(int j=0;j<2;j++)
   if(g[i][j]<=rem&&rem<=f[i][j]&&a[i][j]<=p)
    res[i]='A'+j,rem-=j,p=a[i][j],flag=true;
  if(!flag)
  {
   cout<<-1<<endl;
   return 0;
  }
 }
 cout<<(res+1)<<endl;
 return 0;
}