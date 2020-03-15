#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull t[100005],b[100005],s1[100005],s2[100005];
int p[100005],q[100005];
int main()
{
 ios::sync_with_stdio(false);
 ull A,B,C;
 int n,m;
 cin>>A>>B>>C;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>t[i];
 for(int i=1;i<=m;i++)
  cin>>b[i];
 sort(t+1,t+n+1);
 sort(b+1,b+m+1);
 for(int i=1;i<=n;i++)
  p[t[i]]++,s1[i]=s1[i-1]+t[i];
 for(int i=1;i<=m;i++)
  q[b[i]]++,s2[i]=s2[i-1]+b[i];
 ull ans=-1ull;
 ull cnt=n,x=0;
 for(int i=100000;i;i--)
 {
  cnt-=p[i];
  ull res=0;
  if(A>=B)
  {
   ull d=s2[m]-s2[m-x]-x*i;
   res+=max(B*d,0ull);
  }
  else
  {
   ull d1=s2[m]-s2[m-x]-x*i,d2=(m-x)*i-s2[m-x];
   if(d1<=d2)res+=max(d1*A,0ull);
   else res+=max(d2*A+(d1-d2)*B,0ull);
  }
  res+=max((cnt*i-s1[cnt])*C,0ull);
  x+=q[i];
  ans=min(ans,res);
 }
 cout<<ans<<endl;
 return 0;
}