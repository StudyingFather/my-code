#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int c,f,v,type;
}a[4005];
long long f[100005];
bool cmp(const node&a,const node&b)
{
 return a.f>b.f||(a.f==b.f&&a.type<b.type);
}
int main()
{
 int n,m;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].c>>a[i].f>>a[i].v;
  a[i].type=0;
 }
 cin>>m;
 for(int i=n+1;i<=n+m;i++)
 {
  cin>>a[i].c>>a[i].f>>a[i].v;
  a[i].type=1;
 }
 sort(a+1,a+n+m+1,cmp);
 int sc=0;
 memset(f,191,sizeof(f));
 f[0]=0;
 for(int i=1;i<=n+m;i++)
 {
  int t=a[i].type,c=a[i].c,v=a[i].v;
  if(!t)
  {
   for(int j=sc;j>=0;j--)
    f[j+c]=max(f[j+c],f[j]-v);
   sc+=c;
  }
  else
  {
   for(int j=c;j<=sc;j++)
    f[j-c]=max(f[j-c],f[j]+v);
  }
 }
 long long ans=0;
 for(int i=0;i<=sc;i++)
  ans=max(ans,f[i]);
 cout<<ans<<endl;
 return 0;
}