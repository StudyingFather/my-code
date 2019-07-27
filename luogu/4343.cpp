#include <iostream>
#include <algorithm>
using namespace std;
int len,k,x[100005];
long long check(long long num)
{
 long long ans=0,tmp=0;
 for(int i=1;i<=len;i++)
 {
  tmp+=x[i];
  if(tmp<0)tmp=0;
  else if(tmp>=num)ans++,tmp=0;
 }
 return ans;
}
int main()
{
 cin>>len>>k;
 for(int i=1;i<=len;i++)
  cin>>x[i];
 long long l=1,r=1e17,mid,num,mina=-1,maxa=-1;
 while(l<=r)
 {
  mid=(l+r)/2,num=check(mid);
  if(num<=k)
  {
   r=mid-1;
   if(num==k)mina=mid;
  }
  else l=mid+1;
 }
 l=1,r=1e18;
 while(l<=r)
 {
  mid=(l+r)/2,num=check(mid);
  if(num<k)r=mid-1;
  else
  {
   l=mid+1;
   if(num==k)maxa=mid;
  }
 }
 if(mina==-1)cout<<-1<<endl;
 else cout<<mina<<' '<<maxa<<endl;
 return 0;
}