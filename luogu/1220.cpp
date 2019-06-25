#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int pos,w;
}a[55];
int sum[55],f[55][55][2],n,c;
int calc(int x,int y,int l,int r)
{
 return (a[y].pos-a[x].pos)*(sum[l]+sum[n]-sum[r-1]);
}
int main()
{
 scanf("%d%d",&n,&c);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i].pos,&a[i].w);
  sum[i]=sum[i-1]+a[i].w;
 }
 memset(f,INF,sizeof(f));
 f[c][c][0]=f[c][c][1]=0;
 for(int j=c;j<=n;j++)
  for(int i=j-1;i;i--)
  {
   f[i][j][0]=min(f[i+1][j][0]+calc(i,i+1,i,j+1),f[i+1][j][1]+calc(i,j,i,j+1));
   f[i][j][1]=min(f[i][j-1][0]+calc(i,j,i-1,j),f[i][j-1][1]+calc(j-1,j,i-1,j));
  }
 printf("%d\n",min(f[1][n][1],f[1][n][0]));
 return 0;
}