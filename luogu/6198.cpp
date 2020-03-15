#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n,cnt;
int s[1000005],p[1000005];
vector<int> a[1000005];
void dfs(int l,int r,int x)
{
 stack<int> s;
 if(l>r)return;
 for(int i=a[x].size()-1;i>=0;i--)
  if(a[x][i]<=r)s.push(a[x][i]);
  else break;
 while(!s.empty())
 {
  p[s.top()]=++cnt;
  s.pop();
 }
 int u=a[x].back();
 dfs(l,u-1,x+1);
 while(a[x].size()&&a[x].back()<=r)
 {
  dfs(u+1,a[x].back()-1,x+1);
  u=a[x].back();
  a[x].pop_back();
 }
 dfs(u+1,r,x+1);
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i];
  if(s[i]==-1)s[i]=s[i-1]+1;
 }
 for(int i=n;i;i--)
  a[s[i]].push_back(i);
 dfs(1,n,1);
 for(int i=1;i<=n;i++)
  cout<<p[i]<<' ';
 return 0;
}