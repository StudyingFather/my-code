// Problem : #3012. 「JOI 2019 Final」有趣的家庭菜园 3
// Contest : LibreOJ
// URL : https://loj.ac/problem/3012
// Memory Limit : 1024 MB
// Time Limit : 500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
char s[405];
int sum[405][3],pos[405][3],f[405][405][405][3];
int main()
{
 int n;
 cin>>n;
 cin>>(s+1);
 for(int i=1;i<=n;i++)
 {
  int x;
  if(s[i]=='R')
   x=0;
  else if(s[i]=='G')
   x=1;
  else x=2;
  for(int j=0;j<3;j++)
   sum[i][j]=sum[i-1][j];
  sum[i][x]++;
  pos[sum[i][x]][x]=i;
 }
 memset(f,63,sizeof(f));
 f[0][0][0][0]=f[0][0][0][1]=f[0][0][0][2]=0;
 for(int i=0;i<n;i++)
  for(int j=0;j<=sum[n][0];j++)
   for(int k=0;k<=sum[n][1];k++)
    for(int l=0;l<3;l++)
     for(int p=0;p<3;p++)
     {
      if(l==p)continue;
      int x=(p==0),y=2-(p==2);
      int id;
      if(p==0)id=j;
      else if(p==1)id=k;
      else id=i-j-k;
      int curp=pos[id+1][p];
      int a=(x==0?j:k),b=(y==1?k:i-j-k);
      f[i+1][j+(p==0)][k+(p==1)][p]=min(f[i+1][j+(p==0)][k+(p==1)][p],
                                        f[i][j][k][l]+max(0,a-sum[curp][x])+max(0,b-sum[curp][y]));
     }
 int ans=INF;
 for(int i=0;i<3;i++)
  ans=min(ans,f[n][sum[n][0]][sum[n][1]][i]);
 cout<<(ans==INF?-1:ans)<<endl;
 return 0;
}