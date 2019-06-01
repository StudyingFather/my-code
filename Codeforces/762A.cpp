#include <iostream>
using namespace std;
long long a[10000005];
int main()
{
 long long n,k,cnt=0;
 cin>>n>>k;
 for(long long i=1;i*i<=n;i++)
  if(n%i==0)
  {
   a[++cnt]=i;
   k--;
   if(!k)
   {
    cout<<i<<endl;
    return 0;
   }
  }
 if(a[cnt]*a[cnt]==n)cnt--;
 for(int i=cnt;i;i--)
 {
  k--;
  if(!k)
  {
   cout<<n/a[i]<<endl;
   return 0;
  }
 }
 cout<<-1<<endl;
 return 0;
}