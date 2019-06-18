#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,ans;
bool vis[15];
char map[15][15];
void dfs(int h,int tot)
{
 if(tot>=k+1)
 {
  ans++;
  return;
 }
 for(int i=h;i<=n;i++)
 {
  if(n-i+1<k-tot)break; 
  for(int j=1;j<=n;j++)
   if(!vis[j]&&map[i][j]=='#')
   {
    vis[j]=true;
    dfs(i+1,tot+1);
    vis[j]=false;
   }
 }
}
int main()
{
 while(~scanf("%d%d",&n,&k))
 {
  if(n==-1&&k==-1)return 0;
  ans=0;
  for(int i=1;i<=n;i++)
   scanf("%s",map[i]+1);
  dfs(1,1);
  printf("%d\n",ans); 
 }
 return 0;
}
