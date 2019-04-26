#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
 int pid,at,rt,q;
 bool operator<(const node&a)const
 {
  return q<a.q||(q==a.q&&at>a.at);
 }
}a[1500005];
priority_queue<node,vector<node> > q;
int main()
{
 int cnt=1;
 while(cin>>a[cnt].pid>>a[cnt].at>>a[cnt].rt>>a[cnt].q)
  cnt++;
 a[cnt].at=1e9;
 cnt--;
 int todo=0,nxt=1,time=0;
 while(cnt)
 {
  if(!todo)
  {
   q.push(a[nxt]);
   time=a[nxt].at;
   nxt++;
   todo++;
  }
  node cur=q.top();
  q.pop();
  todo--;
  int lt=time;
  time=min(lt+cur.rt,a[nxt].at);
  if(time==lt+cur.rt)
  {
   printf("%d %d\n",cur.pid,time);
   cnt--;
  }
  else
  {
   cur.rt-=time-lt;
   q.push(cur);
   todo++;
  }
  if(time==a[nxt].at)
  {
   q.push(a[nxt]);
   nxt++;
   todo++;
  }
 }
 return 0;
}