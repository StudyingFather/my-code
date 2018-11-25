#include <iostream>
using namespace std;
long long t[1000005],sum;
int a[200005],b[200005],cnt;
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  t[a[i]]++;
  sum+=a[i];
 }
 for(int i=1;i<=n;i++)
  if((sum-a[i])%2==0&&sum-a[i]<=2000000)
  {
   if(a[i]==(sum-a[i])/2)
   {
    if(t[a[i]]>1)b[++cnt]=i;
   }
   else
   {
    if(t[(sum-a[i])/2])b[++cnt]=i;
   }
  }
 cout<<cnt<<endl;
 for(int i=1;i<=cnt;i++)
  cout<<b[i]<<' ';
 return 0;
}