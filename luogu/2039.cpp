/*
 Name: luogu P2039
 Author: StudyingFather
 Date: 2019/10/06 20:31
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#define INF 1e18
using namespace std;
long long f[1005];
int a[1005];
int main()
{
 int n,ans1=0,ans2=0;
 bool flag=true;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(i==1)a[1]=0;
  if(i%2==0)
  {
   if(a[i])ans2++;
   else ans1++;
  }
  if(a[i]&a[i-1])flag=false;
 }
 if(flag)cout<<ans1<<endl<<ans2<<endl;
 else
 {
  cout<<0<<endl;
  long long ans=0;
  for(int i=1;i<=n;i++)
   if(a[i])f[i]=1;
   else f[i]=INF;
  for(int i=1;i<=n;i++)
   if(a[i-1]&&a[i])
   {
    for(int j=i-2;j;j--)
     f[j]=min(f[j],f[j+1]+f[j+2]);
    for(int j=i+1;j<=n;j++)
     f[j]=min(f[j],f[j-1]+f[j-2]);
   }
  for(int i=2;i<=n;i+=2)
   ans+=f[i];
  cout<<ans<<endl;
 }
 return 0;
}