/*
 Name: luogu P1912
 Author: StudyingFather
 Date: 2019/10/24 17:56
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
using namespace std;
char s[100005][35];
int sum[100005],q[100005],pt[100005],res[100005],ans[100005];
int n,l,p;
long double f[100005];
long double fpow(long double x,int y)
{
 long double ans=1;
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
long double calc(int x,int y)
{
 return f[x]+fpow(abs(sum[y]-sum[x]-1-l),p);
}
int find(int x,int y)
{
 int l=x,r=n+1;
 while(l<r)
 {
  int mid=(l+r)>>1;
  if(calc(x,mid)>=calc(y,mid))r=mid;
  else l=mid+1;
 }
 return l;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  cin>>n>>l>>p;
  for(int i=1;i<=n;i++)
  {
   cin>>s[i];
   sum[i]=sum[i-1]+strlen(s[i])+1;
  }
  memset(q,0,sizeof(q));
  int l=0,r=0;
  for(int i=1;i<=n;i++)
  {
   while(l<r&&pt[l]<=i)
    l++;
   f[i]=calc(q[l],i);
   res[i]=q[l];
   while(l<r&&pt[r-1]>=find(q[r],i))
    r--;
   pt[r]=find(q[r],i);
   q[++r]=i;
  }
  if(f[n]>1e18)cout<<"Too hard to arrange"<<endl;
  else
  {
   cout<<(long long)f[n]<<endl;
   int cnt=0;
   ans[0]=n;
   for(int i=n;i;i=res[i])
    ans[++cnt]=res[i];
   for(int i=cnt;i;i--)
   {
    for(int j=ans[i]+1;j<ans[i-1];j++)
     cout<<s[j]<<' ';
    cout<<s[ans[i-1]]<<endl;
   }
  }
  cout<<"--------------------"<<endl;
 }
 return 0;
}