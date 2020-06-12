#include "Anthony.h"
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
vector<pii> e[20005];
int dis[20005],fac[20005];
namespace col01
{
 vector<int> res;
 const int col[]={0,1,0,0,1,1};
 void dfs(int u,int fa,int p)
 {
  for(auto E:e[u])
  {
   int v=E.first,id=E.second;
   if(v==fa)continue;
   res[id]=col[p];
   if(e[v].size()>2)
    dfs(v,u,!col[p]);
   else
    dfs(v,u,(p+1)%6);
  }
 }
 vector<int> solve(int M)
 {
  res.resize(M);
  dfs(0,-1,0);
  return res;
 }
}
vector<int> Mark(int N,int M,int A,int B,vector<int> U,vector<int> V)
{
 for(int i=0;i<M;i++)
 {
  e[U[i]].push_back(make_pair(V[i],i));
  e[V[i]].push_back(make_pair(U[i],i));
 }
 if(A>=3)
 {
  queue<int> q;
  vector<int> res(M);
  memset(dis,-1,sizeof(dis));
  q.push(0);
  dis[0]=0;
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(auto E:e[u])
   {
    int v=E.first;
    if(dis[v]==-1)
    {
     dis[v]=dis[u]+1;
     q.push(v);
    }
   }
  }
  for(int i=0;i<M;i++)
   res[i]=min(dis[U[i]],dis[V[i]])%3;
  return res;
 }
 else return col01::solve(M);
}