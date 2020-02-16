#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> e[2000005];
int son[2000005],a[2000005],l[2000005],r[2000005],id[2000005];
int ans,n,m,cnt;
bool cmp(int x,int y)
{
 return son[x]+a[x]<son[y]+a[y];
}
void dfs(int u)
{
 if(!son[u])return;
 for(auto v:e[u])
  dfs(v);
 sort(id+l[u],id+r[u]+1,cmp);
 for(int i=l[u];i<=r[u];i++)
 {
  int v=id[i];
  if(son[u]+a[u]+son[v]+a[v]-1<=m)
  {
   son[u]+=son[v]-1;
   a[u]+=a[v];
   ans++;
  }
 }
 return;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=0;i<n;i++)
  cin>>a[i];
 for(int i=0;i<n;i++)
 {
  cin>>son[i];
  l[i]=cnt+1,r[i]=cnt+son[i];
  for(int j=1;j<=son[i];j++)
  {
   int x;
   cin>>x;
   id[++cnt]=x;
   e[i].push_back(x);
  }
 }
 dfs(0);
 cout<<ans<<endl;
 return 0;
}