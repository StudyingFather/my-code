#include <iostream>
using namespace std;
int sum[100005],num[200005];
int main()
{
 int n,k;
 cin>>n>>k;
 sum[0]=n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  if(x>=k)sum[i]=sum[i-1]+1;
  else sum[i]=sum[i-1]-1;
 }
 num[n]=1;
 int pre=0;
 long long ans=0;
 for(int i=1;i<=n;i++)
 {
  if(sum[i]>sum[i-1])
   pre+=num[sum[i]]+1;
  else
   pre-=num[sum[i-1]]-1;
  num[sum[i]]++;
  ans+=pre;
 }
 cout<<ans<<endl;
 return 0;
}