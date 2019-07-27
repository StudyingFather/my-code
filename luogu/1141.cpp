#include <cstdio>
#include <algorithm>
using namespace std;
int fa[1000005],siz[1000005];
char s[1005][1005];
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 x=find(x),y=find(y);
 if(x==y)return;
 fa[x]=y;
 siz[y]+=siz[x];
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=n*n;i++)
  fa[i]=i,siz[i]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   if(abs(s[i][j]-s[i][j-1])==1)unionn((i-1)*n+j,(i-1)*n+j-1);
   if(abs(s[i][j]-s[i-1][j])==1)unionn((i-1)*n+j,(i-2)*n+j);
  }
 while(m--)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  printf("%d\n",siz[find((x-1)*n+y)]);
 }
 return 0;
}