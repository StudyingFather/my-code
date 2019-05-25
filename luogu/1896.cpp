#include <iostream>
#include <algorithm>
using namespace std;
long long sta[2005],sit[2005],f[15][2005][105];
int n,k,cnt;
void dfs(int x,int num,int cur)
{
 if(cur>=n)
 {
  sit[++cnt]=x;
  sta[cnt]=num;
  return;
 }
 dfs(x,num,cur+1);
 dfs(x+(1<<cur),num+1,cur+2);
}
int main()
{
 cin>>n>>k;
 dfs(0,0,0);
 for(int i=1;i<=cnt;i++)
  f[1][i][sta[i]]=1;
 for(int i=2;i<=n;i++)
  for(int j=1;j<=cnt;j++)
   for(int l=1;l<=cnt;l++)
   {
    if(sit[j]&sit[l])continue;
    if((sit[j]<<1)&sit[l])continue;
    if(sit[j]&(sit[l]<<1))continue;
    for(int p=sta[j];p<=k;p++)
     f[i][j][p]+=f[i-1][l][p-sta[j]];
   }
 long long ans=0;
 for(int i=1;i<=cnt;i++)
  ans+=f[n][i][k];
 cout<<ans<<endl;
 return 0;
}