/*
 Name: Codeforces 1230C (greedy solution)
 Author: StudyingFather
 Date: 2019/09/24 20:48
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int t[15],f[15][15];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  t[x]++,t[y]++;
  f[x][y]=f[y][x]=1;
 }
 if(n<=6)printf("%d\n",m);
 else
 {
  int res=m,ans=0;
  for(int k=1;k<=7;k++)
   for(int i=1;i<=7;i++)
   {
    if(i==k)continue;
    res=m;
    for(int j=1;j<=7;j++)
     if(j!=k&&f[i][j]&&f[j][k])res--;
    ans=max(ans,res);
   }
  printf("%d\n",ans);
 }
 return 0;
}