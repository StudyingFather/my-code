#include <cmath>
#include <iostream>
using namespace std;
int b[200005],l[200005],k[200005];
int f[200005],g[200005];
int n,m;
int query(int x)
{
 int ans=0;
 while(x<=n)
 {
  ans+=f[x];
  x=g[x];
 }
 return ans;
}
void update(int x,int y)
{
 k[x]=y;
 for(int i=l[b[x]+1]-1;i>=l[b[x]];i--)
  if(i+k[i]>=l[b[i]+1])
  {
   f[i]=1;
   g[i]=i+k[i];
  }
  else
  {
   f[i]=f[i+k[i]]+1;
   g[i]=g[i+k[i]];
  }
}
int main()
{
 cin>>n;
 int siz=sqrt(n);
 for(int i=1;i<=n;i++)
 {
  cin>>k[i];
  b[i]=(i-1)/siz+1;
  if(b[i]!=b[i-1])l[b[i]]=i;
 }
 l[b[n]+1]=n+1;
 for(int i=n;i;i--)
  if(i+k[i]>=l[b[i]+1])
  {
   f[i]=1;
   g[i]=i+k[i];
  }
  else
  {
   f[i]=f[i+k[i]]+1;
   g[i]=g[i+k[i]];
  }
 cin>>m;
 while(m--)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int x;
   cin>>x;
   x++;
   cout<<query(x)<<endl;
  }
  else
  {
   int x,y;
   cin>>x>>y;
   x++;
   update(x,y);
  }
 }
 return 0;
}