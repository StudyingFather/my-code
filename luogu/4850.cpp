#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int f[55][55][55][55],a[55][55],s[55][55];
int dfs(int x1,int y1,int x2,int y2)
{
 if(x1==x2&&y1==y2)return 0;
 if(f[x1][y1][x2][y2]!=INF)return f[x1][y1][x2][y2];
 for(int i=x1;i<x2;i++)
  f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
 for(int i=y1;i<y2;i++)
  f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dfs(x1,y1,x2,i)+dfs(x1,i+1,x2,y2));
 return f[x1][y1][x2][y2]+=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
int main()
{
 memset(f,63,sizeof(f));
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   cin>>a[i][j];
   s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
  }
 cout<<dfs(1,1,n,m)<<endl;
 return 0;
}