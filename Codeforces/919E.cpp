#include <iostream>
using namespace std;
long long l1[1000005],l2[1000005];
long long a,b,p,x,ans,re,arr;
long long gcd(long long a,long long b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 cin>>a>>b>>p>>x;
 long long num=1;
 re=b%p;
 while(true)
 {
  num*=a;
  num%=p;
  if(l2[num])break;
  l2[num]=1;
  l1[++arr]=num;
 }
 long long lcm=arr*p/gcd(arr,p);
 for(int i=1;i<=arr;i++)
 {
  for(int j=0;(j*p+b)<=x;j++)
   if((j*p+b)%p==re&&j%arr==i%arr)
   {
   	ans+=(x-(j*p+b))/lcm+1;
   	break;
   }
 }
 cout<<ans;
 return 0;
}
