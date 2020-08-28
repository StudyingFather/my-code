// Problem : Alien Piano
// Contest : Google Coding Competitions - Round D 2020 - Kick Start 2020
// URL : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174
// Memory Limit : 1024 MB
// Time Limit : 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10005],f[10005][5];
bool check(int x,int y,int z)
{
 if(y>z)return a[x]<=a[x-1];
 else if(y==z)return a[x]!=a[x-1];
 else return a[x]>=a[x-1];
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  memset(f,63,sizeof(f));
  for(int i=1;i<=4;i++)
   f[1][i]=0;
  for(int i=2;i<=n;i++)
   for(int j=1;j<=4;j++)
    for(int k=1;k<=4;k++)
     f[i][j]=min(f[i][j],f[i-1][k]+check(i,j,k));
  int ans=10005;
  for(int i=1;i<=4;i++)
   ans=min(ans,f[n][i]);
  printf("Case #%d: %d\n",kase,ans);
 }
 return 0;
}