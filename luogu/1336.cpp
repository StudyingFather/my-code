#include <iostream>
#include <queue>
using namespace std;
long long ans;
struct node
{
 int id;
 long long t;
 bool operator<(const node&a)const
 {
  return t>a.t;
 }
};
priority_queue<node> q;
int a[25],b[25],cnt[25],st[25];
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y--)
  ans*=x;
 return ans;
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>a[i]>>b[i];
  q.push({i,a[i]});
  cnt[i]=1;
 }
 while(n--)
 {
  int id=q.top().id;
  long long t=q.top().t;
  q.pop();
  ans+=t;
  cnt[id]++;
  st[id]+=t;
  q.push({id,a[id]*fpow(cnt[id],b[id])-st[id]});
 }
 cout<<ans<<endl;
 return 0;
}