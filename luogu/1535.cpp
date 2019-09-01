/*
 Name: luogu P1535
 Author: StudyingFather
 Date: 2019/08/21 16:03
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,t,r1,c1,r2,c2,f[105][105][25];
char ma[105][105];
int main()
{
 scanf("%d%d%d",&n,&m,&t);
 for(int i=1;i<=n;i++)
  scanf("%s",ma[i]+1);
 scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
 memset(f,0,sizeof(f));
 f[r1][c1][0]=1;
 for(int k=0;k<t;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    for(int l=0;l<4;l++)
    {
     int x=i+dx[l],y=j+dy[l];
     if(ma[x][y]!='*')f[x][y][k+1]+=f[i][j][k];
    }
 printf("%d\n",f[r2][c2][t]);
 return 0;
}