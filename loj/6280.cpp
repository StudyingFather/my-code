// Problem: #6280. 数列分块入门 4
// Contest: LibreOJ
// URL: https://loj.ac/problem/6280
// Memory Limit: 256 MB
// Time Limit: 500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cmath>
#include <iostream>
using namespace std;
int id[50005],len;
long long a[50005],b[50005],s[50005];
void add(int l,int r,long long x)
{
 int sid=id[l],eid=id[r];
 if(sid==eid)
 {
  for(int i=l;i<=r;i++)
   a[i]+=x,s[sid]+=x;
  return;
 }
 for(int i=l;id[i]==sid;i++)
  a[i]+=x,s[sid]+=x;
 for(int i=sid+1;i<eid;i++)
  b[i]+=x,s[i]+=len*x;
 for(int i=r;id[i]==eid;i--)
  a[i]+=x,s[eid]+=x;
}
long long query(int l,int r,long long p)
{
 int sid=id[l],eid=id[r];
 long long ans=0;
 if(sid==eid)
 {
  for(int i=l;i<=r;i++)
   ans=(ans+a[i]+b[sid])%p;
  return ans;
 }
 for(int i=l;id[i]==sid;i++)
  ans=(ans+a[i]+b[sid])%p;
 for(int i=sid+1;i<eid;i++)
  ans=(ans+s[i])%p;
 for(int i=r;id[i]==eid;i--)
  ans=(ans+a[i]+b[eid])%p;
 return ans;
}
int main()
{
 int n;
 cin>>n;
 len=sqrt(n);
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  id[i]=(i-1)/len+1;
  s[id[i]]+=a[i];
 }
 for(int i=1;i<=n;i++)
 {
  int op,l,r,c;
  cin>>op>>l>>r>>c;
  if(op==0)add(l,r,c);
  else cout<<query(l,r,c+1)<<endl;
 }
 return 0;
}