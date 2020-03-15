#include <iostream>
using namespace std;
int a[1000005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int l,r;
  cin>>l>>r;
  a[l]++,a[r]--;
 }
 int res=0,l=1000000,ans1=0,ans2=0;
 bool flag=false;
 for(int t=0;t<=1000000;t++)
 {
  res+=a[t];
  if(res&!flag)
  {
   flag=true;
   ans2=max(t-l,ans2);
   l=t;
  }
  if(!res&flag)
  {
   flag=false;
   ans1=max(t-l,ans1);
   l=t;
  }
 }
 cout<<ans1<<' '<<ans2<<endl;
 return 0;
}