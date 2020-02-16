#include <iostream>
#include <algorithm>
using namespace std;
int colt[10005],last[10005],sum[10005];
int main()
{
 ios::sync_with_stdio(false);
 int n,k,p,tmp=0;
 long long ans=0;
 cin>>n>>k>>p;
 for(int i=1;i<=n;i++)
 {
  int col,cost;
  cin>>col>>cost;
  if(cost<=p)tmp=i;
  if(tmp>=last[col])sum[col]=colt[col];
  last[col]=i;
  ans+=sum[col];
  colt[col]++;
 }
 cout<<ans<<endl;
 return 0;
}