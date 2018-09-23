#include <cstdio>
#include <queue>
using namespace std;
struct N
{
 int num,t,time;
 bool operator<(const N&p)const
 {
  return p.time<time||(p.time==time&&p.num<num);
 }
};
int main()
{
 int k;
 char a[20];
 priority_queue<N>pq;
 N n;
 while(scanf("%s",a)&&(a[0]!='#'))
 {
  scanf("%d %d",&n.num,&n.t);
  n.time=n.t;
  pq.push(n);
 }
 scanf("%d",&k);
 while(k--)
 {
  N w=pq.top();
  pq.pop();
  printf("%d\n",w.num);
  w.time+=w.t;
  pq.push(w);
 }
 return 0;
}
