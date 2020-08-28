// Problem: P4155 [SCOI2015]国旗计划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4155
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
 int l,r,id;
 node(int l,int r,int id):l(l),r(r),id(id){}
 bool operator<(const node&a)const
 {
  return l<a.l;
 }
};
vector<node> v;
int n,m,ans[200005],f[400005][25];
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 v.emplace_back(0,0,0);
 for(int i=1;i<=n;i++)
 {
  int l,r;
  cin>>l>>r;
  if(l>r)r+=m;
  v.emplace_back(l,r,i);
  v.emplace_back(l+m,r+m,i);
 }
 sort(v.begin(),v.end());
 for(int i=1,j=1;i<=2*n;i++)
 {
  while(j<=2*n&&v[j].l<=v[i].r)
   j++;
  f[i][0]=j-1;
 }
 for(int j=1;j<=20;j++)
  for(int i=1;i<=2*n;i++)
   f[i][j]=f[f[i][j-1]][j-1];
 for(int i=1;i<=n;i++)
 {
  int id=v[i].id,u=i,ed=v[i].l+m;
  for(int k=20;k>=0;k--)
   if(f[u][k]&&v[f[u][k]].r<ed)
   {
    ans[id]+=(1<<k);
    u=f[u][k];
   }
  ans[id]+=2;
 }
 for(int i=1;i<=n;i++)
  cout<<ans[i]<<' ';
 return 0;
}