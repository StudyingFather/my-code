#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> e[100005];
int siz[100005],n,t[100005];
bool dfs(int u,int fa,int k)
{
 multiset<int> m;
 for(auto v:e[u])
  if(v!=fa)
  {
   if(!dfs(v,u,k))return false;
   int tmp=k-siz[v];
   if(m.count(tmp))
   {
    auto it=m.find(tmp);
    m.erase(it);
    siz[u]-=tmp;
   }
   else if(k!=siz[v])
    siz[u]+=siz[v],m.insert(siz[v]);
  }
 siz[u]++;
 if(m.size()>1)
  return false;
 return true;
}
int main()
{
 //freopen("deleg.in","r",stdin);
 //freopen("deleg.out","w",stdout);
 ios::sync_with_stdio(false);
 cin>>n;
 n--;
 for(int i=1;i<=n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
  t[u]++,t[v]++;
 }
 for(int i=1;i<=n;i++)
 {
  if(n%i)cout<<0;
  else
  {
   memset(siz,0,sizeof(siz));
   if(dfs(1,0,i))
    cout<<1;
   else
    cout<<0;
  }
 }
 cout<<endl;
 return 0;
}