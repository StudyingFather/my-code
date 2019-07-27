#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int num,id;
 bool operator<(const node&a)const
 {
  return num>a.num;
 }
};
priority_queue<node> q;
int a[10005],b[10005],c[10005],t[10005];
int calc(int id,int x)
{
 return a[id]*x*x+b[id]*x+c[id];
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d%d",&a[i],&b[i],&c[i]);
  q.push({calc(i,1),i});
  t[i]=1;
 }
 for(int i=1;i<=m;i++)
 {
  node tmp=q.top();
  q.pop();
  t[tmp.id]++;
  q.push({calc(tmp.id,t[tmp.id]),tmp.id});
  printf("%d ",tmp.num);
 }
 return 0;
}