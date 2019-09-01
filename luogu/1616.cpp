/*
 Name: luogu P1616
 Author: StudyingFather
 Date: 2019/08/23 21:47
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long f[100005],a[10005];
int main()
{
 long long t,m,ans=0;
 cin>>t>>m;
 for(int i=1;i<=m;i++)
 {
  long long x,y;
  cin>>x>>y;
  a[x]=max(a[x],y);
 }
 for(int i=1;i<=10000;i++)
  if(a[i])
   for(int j=i;j<=t;j++)
   {
    f[j]=max(f[j],f[j-i]+a[i]);
    ans=max(ans,f[j]);
   }
 cout<<ans<<endl;
 return 0;
}