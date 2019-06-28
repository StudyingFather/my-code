#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,ans=INF,a[105][105],d[105][105],pos[105][105];
vector<int> path;
void seta()
{
 for(int i=1;i<=100;i++)
  a[i][i]=0;
}
void get_path(int s,int t)
{
 if(!pos[s][t])return;
 get_path(s,pos[s][t]);
 path.push_back(pos[s][t]);
 get_path(pos[s][t],t);
}
int main()
{
 memset(a,INF,sizeof(a));
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int s,t,v;
  scanf("%d%d%d",&s,&t,&v);
  a[s][t]=a[t][s]=min(a[t][s],v);//可能出现重边
 }
 memcpy(d,a,sizeof(a));
 for(int k=1;k<=n;k++)
 {
  for(int i=1;i<k;i++)
   for(int j=i+1;j<k;j++)
   {
    if((long long)d[i][j]+a[j][k]+a[k][i]<ans)//更新路径
    {
     ans=d[i][j]+a[j][k]+a[k][i];
     path.clear();
     path.push_back(i);
     get_path(i,j);//递归求i,j间的路径
     path.push_back(j);
     path.push_back(k);
    }
   }
  for(int i=1;i<=n;i++)//Floyd求最短路，并更新中转点
   for(int j=1;j<=n;j++)
   {
    if(d[i][k]+d[k][j]<d[i][j])
    {
     d[i][j]=d[i][k]+d[k][j];
     pos[i][j]=k;
    }
   }
 }
 if(ans==INF)puts("No solution.");
 else
  for(int i=0;i<path.size();i++)//输出路径
   printf("%d ",path[i]);
 return 0;
}
