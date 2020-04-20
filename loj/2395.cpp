#include <iostream>
#include <stack>
using namespace std;
int l[100005],f[100005][25],g[100005][25];
stack<int> s;
int main()
{
 ios::sync_with_stdio(false);
 int n,k,q;
 cin>>n>>k>>q;
 for(int i=1;i<=n;i++)
  cin>>l[i];
 for(int i=1;i<=n;i++)
 {
  while(!s.empty()&&l[s.top()]<l[i])
   s.pop();
  if(!s.empty())f[i][0]=s.top();
  else f[i][0]=i;
  s.push(i);
 }
 while(!s.empty())
  s.pop();
 for(int i=n;i;i--)
 {
  while(!s.empty()&&l[s.top()]<l[i])
   s.pop();
  if(!s.empty())g[i][0]=s.top();
  else g[i][0]=i;
  s.push(i);
 }
 for(int k=1;k<=16;k++)
  for(int i=1;i<=n;i++)
  {
   f[i][k]=min(f[f[i][k-1]][k-1],f[g[i][k-1]][k-1]);
   g[i][k]=max(g[f[i][k-1]][k-1],g[g[i][k-1]][k-1]);
  }
 while(q--)
 {
  int a,b,l,r;
  cin>>a>>b;
  if(a>b)swap(a,b);
  int ans=0;
  l=r=a;
  for(int k=16;k>=0;k--)
  {
   int u=min(f[l][k],f[r][k]),v=max(g[l][k],g[r][k]);
   if(v<b)
   {
    l=u,r=v;
    ans+=(1<<k);
   }
  }
  a=r;
  l=r=b;
  for(int k=16;k>=0;k--)
  {
   int u=min(f[l][k],f[r][k]),v=max(g[l][k],g[r][k]);
   if(u>a)
   {
    l=u,r=v;
    ans+=(1<<k);
   }
  }
  cout<<ans<<endl;
 }
 return 0;
}