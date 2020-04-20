#include <iostream>
#include <map>
using namespace std;
int a[100005],sa[100005],sb[100005];
map<int,int> ma,mb;
int main()
{
 int n,b,pos;
 long long ans=0;
 cin>>n>>b;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  if(x>b)a[i]=1;
  else if(x<b)a[i]=-1;
  else a[i]=0,pos=i;
 }
 for(int i=pos;i;i--)
 {
  sa[i]=sa[i+1]+a[i];
  ma[sa[i]]++;
 }
 for(int i=pos;i<=n;i++)
 {
  sb[i]=sb[i-1]+a[i];
  mb[sb[i]]++;
 }
 for(int i=-n;i<=n;i++)
  ans+=1ll*ma[i]*mb[-i];
 cout<<ans<<endl;
 return 0;
}