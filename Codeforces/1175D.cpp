#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long r,num;
}b[300005];
long long a[300005],q[300005],sum[300005];
bool cmp(const node&a,const node&b)
{
 return a.num<b.num||(a.num==b.num&&a.r<b.r);
}
int main()
{
 long long n,k,ans=0;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  b[i].r=i;
  sum[i]=b[i].num=b[i-1].num+a[i];
 }
 sort(b+1,b+n+1,cmp);
 for(int i=1;i<k;i++)
  q[i]=b[i].r;
 sort(q+1,q+k);
 if(q[k-1]==n)q[k-1]=b[k].r;
 for(int i=1;i<k;i++)
  ans+=i*(sum[q[i]]-sum[q[i-1]]);
 ans+=k*(sum[n]-sum[q[k-1]]);
 cout<<ans<<endl;
 //for(int i=1;i<k;i++)
 // cout<<q[i]<<' ';
 return 0;
}