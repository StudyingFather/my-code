#include <cstring>
#include <iostream>
using namespace std;
int a[35][35],f[35],g[100005],sum[35][100005];
char s[100005];
int main()
{
 int n,m,k;
 cin>>n>>m>>k>>(s+1);
 for(int i=1;i<=n;i++)
  s[i]-='a';
 for(int i=0;i<m;i++)
  for(int j=0;j<m;j++)
   cin>>a[i][j];
 for(int k=0;k<m;k++)
  for(int i=0;i<m;i++)
   for(int j=0;j<m;j++)
    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
 for(int i=0;i<m;i++)
  for(int j=1;j<=n;j++)
   sum[i][j]=sum[i][j-1]+a[s[j]][i];
 memset(f,63,sizeof(f));
 memset(g,63,sizeof(g));
 g[0]=0;
 for(int i=k;i<=n;i++)
  for(int j=0;j<m;j++)
  {
   f[j]=min(f[j]+a[s[i]][j],g[i-k]+sum[j][i]-sum[j][i-k]);
   g[i]=min(g[i],f[j]);
  }
 cout<<g[n]<<endl;
 return 0;
}