
// Problem: P5471 [NOI2019]弹跳
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5471
// Memory Limit: 125 MB
// Time Limit: 2200 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
struct point
{
 int x,y,id;
 bool operator<(const point&a)const
 {
  return y<a.y||(y==a.y&&x<a.x);
 }
}p[70005];
struct edge
{
 int p,t,l,r,d,u;
}e[150005];
struct node
{
 int u,dis;
 bool operator>(const node&a)const
 {
  return dis>a.dis;
 }
};
vector<int> f[70005];
set<point> s[300005];
priority_queue<node,vector<node>,greater<node> > q;
int dis[70005],vis[150005];
int n,m,w,h;
void add(int root,int l,int r,int x)
{
 s[root].insert(p[x]);
 if(l==r)return;
 int mid=(l+r)>>1;
 if(p[x].x<=mid)add(root<<1,l,mid,x);
 else add(root<<1|1,mid+1,r,x);
}
void del(int root,int l,int r,int x)
{
 s[root].erase(p[x]);
 if(l==r)return;
 int mid=(l+r)>>1;
 if(p[x].x<=mid)del(root<<1,l,mid,x);
 else del(root<<1|1,mid+1,r,x);
}
void modify(int root,int cl,int cr,int x,int d)
{
 queue<int> dq;
 int l=e[x].l,r=e[x].r;
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  auto it=s[root].lower_bound((point){0,e[x].d,0});
  for(;it!=s[root].end()&&it->y<=e[x].u;it++)
  {
   int u=it->id;
   dis[u]=d;
   dq.push(u);
   for(auto v:f[u])
    q.push({v,d+e[v].t});
  }
  while(!dq.empty())
  {
   int u=dq.front();
   dq.pop();
   del(1,1,n,u);
  }
  return;
 }
 int mid=(cl+cr)>>1;
 modify(root<<1,cl,mid,x,d);
 modify(root<<1|1,mid+1,cr,x,d);
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&w,&h);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&p[i].x,&p[i].y);
  p[i].id=i;
  add(1,1,n,i);
 }
 for(int i=1;i<=m;i++)
 {
  scanf("%d%d%d%d%d%d",&e[i].p,&e[i].t,&e[i].l,&e[i].r,&e[i].d,&e[i].u);
  f[e[i].p].push_back(i);
 }
 e[0].l=e[0].r=p[1].x;
 e[0].d=e[0].u=p[1].y;
 q.push({0,0});
 while(!q.empty())
 {
  int u=q.top().u,d=q.top().dis;
  q.pop();
  if(vis[u])continue;
  vis[u]=1;
  modify(1,1,n,u,d);
 }
 for(int i=2;i<=n;i++)
  printf("%d\n",dis[i]);
 return 0;
}