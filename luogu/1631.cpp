#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int sum,ida,idb;
 bool operator<(const node&a)const
 {
  return sum>a.sum;
 }
};
priority_queue<node> q;
int a[100005],b[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 for(int i=1;i<=n;i++)
  q.push({a[1]+b[i],1,i});
 for(int i=1;i<=n;i++)
 {
  node u=q.top();
  q.pop();
  q.push({a[u.ida+1]+b[u.idb],u.ida+1,u.idb});
  printf("%d ",u.sum);
 }
 return 0;
}