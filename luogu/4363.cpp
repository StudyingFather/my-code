/*
 Name: luogu P4363
 Author: StudyingFather
 Date: 2019/10/07 15:28
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,a[15][15],b[15][15],f[2000005];
int dfs(int s,int p)
{
 if(f[s]!=-1)return f[s];
 if(p)f[s]=-INF;
 else f[s]=INF;
 int x=n,y=0;
 for(int i=0;i<n+m-1;i++)
 {
  if((s>>i)&1)x--;
  else y++;
  if(((s>>i)&3)!=1)continue;
  int tmp=s^(3<<i);
  if(p)f[s]=max(f[s],dfs(tmp,p^1)+a[x][y]);
  else f[s]=min(f[s],dfs(tmp,p^1)-b[x][y]);
 }
 return f[s];
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
   scanf("%d",&a[i][j]);
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
   scanf("%d",&b[i][j]);
 memset(f,-1,sizeof(f));
 f[((1<<n)-1)<<m]=0;
 printf("%d\n",dfs((1<<n)-1,1));
 return 0;
}