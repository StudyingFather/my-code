#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int id,x;
}a[200005];
int pre[200005],post[200005];
int b[200005],ans[200005];
bool cmp(const node&a,const node&b)
{
 return a.x<b.x;
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n+1;i++)
 {
  cin>>a[i].x;
  a[i].id=i;
 }
 for(int i=1;i<=n;i++)
  cin>>b[i];
 sort(a+1,a+n+2,cmp);
 sort(b+1,b+n+1);
 for(int i=1;i<=n;i++)
  pre[i]=max(pre[i-1],max(a[i].x-b[i],0));
 for(int i=n;i;i--)
  post[i]=max(post[i+1],max(a[i+1].x-b[i],0));
 for(int i=1;i<=n+1;i++)
  ans[a[i].id]=max(pre[i-1],post[i]);
 for(int i=1;i<=n+1;i++)
  cout<<ans[i]<<' ';
 cout<<endl;
 return 0;
}