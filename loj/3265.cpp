#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[100005],e[100005];
int s[100005];
bool check2(int u,int p,int x)
{
 int siz=vec[u].size();
 for(int i=0,j=siz-1;i<j;i++,j--)
 {
  if(i==p)i++;
  if(j==p)j--;
  if(vec[u][i]+vec[u][j]<x)return false;
 }
 return true;
}
bool check(int u,int fa,int x)
{
 vec[u].clear();
 for(auto v:e[u])
 {
  if(v==fa)continue;
  if(!check(v,u,x))return false;
  vec[u].push_back(s[v]+1);
 }
 if(fa&&vec[u].size()%2==0)vec[u].push_back(0);
 else if(!fa&&vec[u].size()%2!=0)vec[u].push_back(0);
 sort(vec[u].begin(),vec[u].end());
 int siz=vec[u].size();
 if(!fa)
 {
  for(int i=0;i<siz/2;i++)
   if(vec[u][i]+vec[u][siz-i-1]<x)
    return false;
 }
 else
 {
  int ans=0;
  if(!check2(u,0,x))return false;
  int l=0,r=siz-1;
  while(l<=r)
  {
   int mid=(l+r)>>1;
   if(check2(u,mid,x))ans=mid,l=mid+1;
   else r=mid-1;
  }
  s[u]=vec[u][ans];
 }
 return true;
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
 int l=1,r=n-1,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  memset(s,0,sizeof(s));
  if(check(1,0,mid))ans=mid,l=mid+1;
  else r=mid-1;
 }
 cout<<ans<<endl;
 return 0;
}