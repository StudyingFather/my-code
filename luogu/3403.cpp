/*
 Name: luogu P3403
 Author: StudyingFather
 Date: 2019/10/09 18:10
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
queue<int> q;
int vis[100005];
long long dist[100005],h,x,y,z,ans;
int main()
{
 cin>>h>>x>>y>>z;
 memset(dist,INF,sizeof(dist));
 dist[1%x]=1,vis[1%x]=1;
 q.push(1%x);
 while(!q.empty())
 {
  long long u=q.front();
  q.pop();
  vis[u]=0;
  long long v=(u+y)%x;
  if(dist[v]>dist[u]+y)
  {
   dist[v]=dist[u]+y;
   if(!vis[v])vis[v]=1,q.push(v);
  }
  v=(u+z)%x;
  if(dist[v]>dist[u]+z)
  {
   dist[v]=dist[u]+z;
   if(!vis[v])vis[v]=1,q.push(v);
  }
 }
 for(int i=0;i<x;i++)
  if(dist[i]<=h)ans+=(h-dist[i])/x+1;
 cout<<ans<<endl;
 return 0;
}