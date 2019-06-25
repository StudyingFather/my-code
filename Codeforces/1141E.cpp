#include <iostream>
#include <algorithm>
using namespace std;
long long d[200005],f[200005];
int main()
{
 long long h,n,sum=0,mins=2147483647;
 cin>>h>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>d[i];
  sum+=d[i];
  f[i]=sum;
  mins=min(sum,mins);
  if(h+sum<=0)
  {
   cout<<i<<endl;
   return 0;
  }
 }
 if(sum>=0)cout<<-1<<endl;
 else
 {
  long long ans;
  if((h+mins)%abs(f[n]))ans=(h+mins-f[n])/abs(f[n])*n;
  else ans=(h+mins)/abs(f[n])*n;
  long long cur=h+ans/n*f[n];
  for(int i=1;i<=n;i++)
   if(cur+f[i]<=0)
   {
    cout<<ans+i<<endl;
    return 0;
   }
 }
 return 0;
}