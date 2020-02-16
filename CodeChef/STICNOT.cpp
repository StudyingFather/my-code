#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
bool cmp(int x,int y)
{
 return x>y;
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  int n,maxw=0;
  cin>>n;
  for(int i=1;i<n;i++)
  {
   int u,v,w;
   cin>>u>>v>>w;
   a[i]=w;
   maxw=max(maxw,w);
  }
  a[n]=maxw;
  for(int i=1;i<=n;i++)
   cin>>b[i];
  sort(a+1,a+n+1,cmp);
  sort(b+1,b+n+1,cmp);
  int ans=0,cur=1;
  for(int i=1;i<=n;i++)
  {
   if(a[i]>b[cur])ans++;
   else cur++;
  }
  cout<<ans<<endl;
 }
 return 0;
}