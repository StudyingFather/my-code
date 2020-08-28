// Problem: P5811 [IOI2019]景点划分
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5811
// Memory Limit: 1000 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
using namespace std;
vector<int> e[100005],tr[100005];
int dep[100005],siz[100005],maxs[100005],col[100005];
int mind[100005],vis[100005];
int a,b,c,n,m,g,ma[5];
void dfs(int u,int d)
{
 dep[u]=d,siz[u]=1;
 for(auto v:e[u])
  if(!dep[v])
  {
   dfs(v,d+1);
   siz[u]+=siz[v];
   maxs[u]=max(maxs[u],siz[v]);
   tr[u].push_back(v);
  }
}
void dfs2(int u,int s)
{
 vis[u]=1,siz[u]=1;
 for(auto v:e[u])
  if(!vis[v]&&col[u]==col[v])
  {
   dfs2(v,s);
   siz[u]+=siz[v];
   if(s<=siz[v])return;
   s-=siz[v];
  }
 if(s)col[u]=3;
}
void getCol(int u,int c)
{
 col[u]=c;
 for(auto v:tr[u])
  getCol(v,c);
}
int getMind(int u)
{
 int res=n;
 for(auto v:e[u])
  res=min(res,dep[v]);
 for(auto v:tr[u])
  res=min(res,getMind(v));
 return res;
}
void print(int s1,int s2)
{
 for(int i=0;i<n;i++)
  if(col[i]==1)
  {
   dfs2(i,s1-a);
   break;
  }
 for(int i=0;i<n;i++)
  if(col[i]==2)
  {
   dfs2(i,s2-b);
   break;
  }
 for(int i=0;i<n;i++)
  cout<<ma[col[i]]<<' ';
}
int main()
{
 cin>>n>>m;
 cin>>a>>b>>c;
 ma[1]=1,ma[2]=2,ma[3]=3;
 if(a>b)
  swap(a,b),swap(ma[1],ma[2]);
 if(a>c)
  swap(a,c),swap(ma[1],ma[3]);
 if(b>c)
  swap(b,c),swap(ma[2],ma[3]);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v),e[v].push_back(u);
 }
 dfs(0,1);
 for(int i=1;i<n;i++)
  if(a<=siz[i]&&siz[i]<=n-b)
  {
   for(int u=0;u<n;u++)
    col[u]=2;
   getCol(i,1);
   print(siz[i],n-siz[i]);
   return 0;
  }
  else if(b<=siz[i]&&siz[i]<=n-a)
  {
   for(int u=0;u<n;u++)
    col[u]=1;
   getCol(i,2);
   print(n-siz[i],siz[i]);
   return 0;
  }
 for(int i=1;i<n;i++)
  if(max(maxs[i],n-siz[i])<max(maxs[g],n-siz[g]))
   g=i;
 int sum=1;
 for(auto v:e[g])
 {
  mind[v]=getMind(v);
  if(mind[v]>=dep[g])sum+=siz[v];
 }
 if(sum>n-a)
 {
  for(int i=0;i<n;i++)
   cout<<0<<' ';
  return 0;
 }
 for(int u=0;u<n;u++)
  col[u]=1;
 getCol(g,2);
 sum=siz[g];
 for(auto v:tr[g])
  if(mind[v]<dep[g]&&sum>n-a)
   sum-=siz[v],getCol(v,1);
 print(n-sum,sum);
 return 0;
}