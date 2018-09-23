#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long p,c;
}a[100005];
bool cmp(const node&a,const node&b)
{
 return a.p<b.p;
}
int main()
{
 long long n,b,ans=0;
 cin>>n>>b;
 for(int i=1;i<=n;i++)
  cin>>a[i].p>>a[i].c;
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  if(b/a[i].p>=a[i].c)b-=a[i].p*a[i].c,ans+=a[i].c;
  else
  {
   ans+=b/a[i].p;
   break;
  }
 }
 cout<<ans<<endl;
 return 0;
}
