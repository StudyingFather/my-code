#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[100005],np[100005],ans[100005],tot,n;
vector<int> e[100005];
struct bit
{
 int n,s[100005];
 void init(int N)
 {
  n=N;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y)
 {
  while(x<=n)
  {
   s[x]+=y;
   x+=lowbit(x);
  }
 }
 int sum(int x)
 {
  int ans=0;
  while(x)
  {
   ans+=s[x];
   x-=lowbit(x);
  }
  return ans;
 }
}tr;
void dfs(int u)
{
 ans[u]-=(tr.sum(n)-tr.sum(p[u]));
 for(auto v:e[u])
  dfs(v);
 ans[u]+=(tr.sum(n)-tr.sum(p[u]));
 tr.add(p[u],1);
}
int main()
{
 cin>>n;
 tr.init(n);
 for(int i=1;i<=n;i++)
  cin>>np[i],p[i]=np[i];
 sort(np+1,np+n+1);
 for(int i=1;i<=n;i++)
  p[i]=lower_bound(np+1,np+n+1,p[i])-np;
 for(int i=2;i<=n;i++)
 {
  int fa;
  cin>>fa;
  e[fa].push_back(i);
 }
 dfs(1);
 for(int i=1;i<=n;i++)
  cout<<ans[i]<<endl;
 return 0;
}