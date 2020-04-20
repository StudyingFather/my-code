#include <iostream>
using namespace std;
int n,k,t;
long long x[100005],p[100005];
bool check(int s)
{
 for(int i=1;i<=n;i++)
  p[i]=x[i]-1ll*i*t*2*s;
 if(p[1]<p[n])return false;
 int l=k,r=k;
 for(int i=1;i<=k;i++)
  if(p[i]>=p[l])l=i;
 for(int i=k;i<=n;i++)
  if(p[i]<=p[r])r=i;
 int sl=k,sr=k;
 while(l<sl||sr<r)
 {
  bool flag=false;
  int cl=sl,cr=sr;
  while(l<cl&&p[cl-1]>=p[sr])
  {
   cl--;
   if(p[cl]>=p[sl])break;
  }
  if(cl<sl&&p[cl]>=p[sl])flag=true,sl=cl;
  while(cr<r&&p[sl]>=p[cr+1])
  {
   cr++;
   if(p[sr]>=p[cr])break;
  }
  if(sr<cr&&p[sr]>=p[cr])flag=true,sr=cr;
  if(!flag)return false;
 }
 sl=1,sr=n;
 while(l>sl||sr>r)
 {
  bool flag=false;
  int cl=sl,cr=sr;
  while(l>cl&&p[cl+1]>=p[sr])
  {
   cl++;
   if(p[cl]>=p[sl])break;
  }
  if(cl>sl&&p[cl]>=p[sl])flag=true,sl=cl;
  while(cr>r&&p[sl]>=p[cr-1])
  {
   cr--;
   if(p[sr]>=p[cr])break;
  }
  if(sr>cr&&p[sr]>=p[cr])flag=true,sr=cr;
  if(!flag)return false;
 }
 return true;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>k>>t;
 for(int i=1;i<=n;i++)
  cin>>x[i];
 int ans=0,l=0,r=1e9;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,r=mid-1;
  else l=mid+1;
 }
 cout<<ans<<endl;
 return 0;
}