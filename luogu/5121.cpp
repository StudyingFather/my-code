#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
struct node
{
 int x,y;
 bool operator<(const node&a)const
 {
  return x<a.x||(x==a.x&&y<a.y);
 }
};
set<node> se;
char s[105][15];
int vis[105][15],n,k;
int dfs(int x,int y,char cur)
{
 vis[x][y]=1;
 se.insert({x,y});
 int ans=1;
 if((!vis[x-1][y])&&s[x-1][y]==cur)ans+=dfs(x-1,y,cur);
 if((!vis[x+1][y])&&s[x+1][y]==cur)ans+=dfs(x+1,y,cur);
 if((!vis[x][y-1])&&s[x][y-1]==cur)ans+=dfs(x,y-1,cur);
 if((!vis[x][y+1])&&s[x][y+1]==cur)ans+=dfs(x,y+1,cur);
 return ans;
}
int main()
{
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]+1);
 while(1)
 {
  memset(vis,0,sizeof(vis));
  bool flag=false;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=10;j++)
    if((!vis[i][j])&&s[i][j]!='0')
    {
     int cnt=dfs(i,j,s[i][j]);
     if(cnt>=k)
     {
      for(set<node>::iterator it=se.begin();it!=se.end();it++)
       s[(*it).x][(*it).y]='0';
      flag=true;
     }
     se.clear();
    }
  for(int i=n-1;i>=1;i--)
   for(int j=1;j<=10;j++)
   {
    if(s[i][j]=='0')continue;
    int x=i,y=j;
    while(s[x+1][y]=='0')
     swap(s[x][y],s[x+1][y]),x++;
   }
  if(!flag)break;
 }
 for(int i=1;i<=n;i++)
  puts(s[i]+1);
 return 0;
}