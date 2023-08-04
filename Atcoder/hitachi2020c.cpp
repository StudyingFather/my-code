#include <iostream>
#include <vector>
using namespace std;
int col[200005],p[200005],cnt0,cnt1;
vector<int> e[200005];
void dfs(int u,int fa)
{
 col[u]=!col[fa];
 if(col[u])cnt1++;
 else cnt0++;
 for(auto v:e[u])
  if(v!=fa)dfs(v,u);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs(1,1);
 int p1=1,p2=2,p3=3;
 if(cnt0>n/3&&cnt1>n/3)
 {
  for(int i=1;i<=n;i++)
   if(col[i]==0)
   {
    if(p1<=n)p[i]=p1,p1+=3;
    else p[i]=p3,p3+=3;
   }
   else
   {
    if(p2<=n)p[i]=p2,p2+=3;
    else p[i]=p3,p3+=3;
   }
 }
 else if(cnt1<=n/3)
 {
  for(int i=1;i<=n;i++)
   if(col[i]==0)
   {
    if(p1<=n)p[i]=p1,p1+=3;
    else if(p2<=n)p[i]=p2,p2+=3;
    else p[i]=p3,p3+=3;
   }
   else
    p[i]=p3,p3+=3;
 }
 else if(cnt0<=n/3)
 {
  for(int i=1;i<=n;i++)
   if(col[i]==1)
   {
    if(p1<=n)p[i]=p1,p1+=3;
    else if(p2<=n)p[i]=p2,p2+=3;
    else p[i]=p3,p3+=3;
   }
   else
    p[i]=p3,p3+=3;
 }
 for(int i=1;i<=n;i++)
  cout<<p[i]<<' ';
 cout<<endl;
 return 0;
}