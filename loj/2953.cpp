/*
 Name: loj 2953
 Author: StudyingFather
 Date: 2019/08/10 21:13
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> a[5005];
namespace tree
{
 int vis[5005],path[5005],cnt;
 void dfs(int u)
 {
  vis[u]=1;
  path[++cnt]=u;
  int s=a[u].size();
  for(int i=0;i<s;i++)
   if(!vis[a[u][i]])dfs(a[u][i]);
 }
 void solve()
 {
  for(int i=1;i<=n;i++)
   sort(a[i].begin(),a[i].end());
  dfs(1);
  for(int i=1;i<=n;i++)
   printf("%d ",path[i]);
 }
}
namespace loop
{
 int sta[5005],loop[5005],vis[5005],tmp[5005],path[5005],top,siz,fib,cnt;
 bool flag=false;
 void init(int u,int fa)
 {
  vis[u]=1;
  sta[++top]=u;
  int s=a[u].size();
  for(int i=0;i<s;i++)
   if(!vis[a[u][i]])init(a[u][i],u);
   else
   {
    if(fa!=a[u][i]&&!flag)
    {
     int num=top;
     do
     {
      loop[++siz]=sta[num--];
     }while(sta[num]!=a[u][i]);
     loop[++siz]=a[u][i];
     flag=true;
    }
   }
  sta[top--]=0;
 }
 bool is_fib(int u,int v)
 {
  if(u==loop[fib]&&v==loop[fib+1])return true;
  swap(u,v);
  if(u==loop[fib]&&v==loop[fib+1])return true;
  return false;
 }
 bool cmp()
 {
  for(int i=1;i<=n;i++)
   if(tmp[i]>path[i])return false;
   else if(tmp[i]<path[i])return true;
  return false;
 }
 void dfs(int u)
 {
  vis[u]=1;
  tmp[++cnt]=u;
  int s=a[u].size();
  for(int i=0;i<s;i++)
   if(!is_fib(u,a[u][i])&&!vis[a[u][i]])dfs(a[u][i]);
 }
 void solve()
 {
  init(1,0);
  loop[++siz]=loop[1];
  for(int i=1;i<=n;i++)
   sort(a[i].begin(),a[i].end());
  for(int i=1;i<siz;i++)
  {
   memset(vis,0,sizeof(vis));
   fib=i,cnt=0;
   dfs(1);
   if(i==1||cmp())memcpy(path,tmp,sizeof(tmp));
  }
  for(int i=1;i<=n;i++)
   printf("%d ",path[i]);
 }
}
int main()
{
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  a[u].push_back(v);
  a[v].push_back(u);
 }
 if(m==n-1)tree::solve();
 else loop::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
}