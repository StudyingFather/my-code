#include <iostream>
using namespace std;
int d[5005],nd[5005];
long long ds[5005];
int main()
{
 int k,q;
 cin>>k>>q;
 for(int i=1;i<=k;i++)
  cin>>d[i];
 while(q--)
 {
  int n,x,m,cnt=0,ans;
  long long sum;
  cin>>n>>x>>m;
  n--;
  ans=n;
  for(int i=1;i<=k;i++)
  {
   nd[i]=d[i]%m;
   ds[i]=ds[i-1]+nd[i];
   cnt+=(nd[i]==0);
  }
  ans-=n/k*cnt;
  sum=x+n/k*ds[k]+ds[n%k];
  for(int i=1;i<=n%k;i++)
   ans-=(nd[i]==0);
  ans-=sum/m-x/m;
  cout<<ans<<endl;
 }
 return 0;
}