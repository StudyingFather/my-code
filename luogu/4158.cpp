#include <cstdio>
#include <algorithm>
using namespace std;
char s[55][55];
int f[55][55][2505][2];
int main()
{
 int n,m,t;
 scanf("%d%d%d",&n,&m,&t);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   for(int k=1;k<=t;k++)
    if(j==1)
    {
     f[i][j][k][0]=max(f[i-1][m][k-1][0],f[i-1][m][k-1][1]);
     f[i][j][k][1]=max(f[i-1][m][k-1][0],f[i-1][m][k-1][1])+1;
    }
    else
    {
     if(s[i][j]==s[i][j-1])
     {
      f[i][j][k][1]=f[i][j-1][k][1]+1;
      f[i][j][k][0]=f[i][j-1][k][0];
     }
     else
     {
      f[i][j][k][1]=max(f[i][j-1][k-1][1]+1,f[i][j-1][k][0]+1);
      f[i][j][k][0]=max(f[i][j-1][k-1][0],f[i][j-1][k][1]);
     }
    }
 int ans=0;
 for(int i=1;i<=t;i++)
  ans=max(ans,max(f[n][m][i][1],f[n][m][i][0]));
 printf("%d\n",ans);
 return 0;
}