#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int cnt,num;
};
queue <node> q;
int n,k;
bool vis[100005];
int main()
{
 scanf("%d%d",&n,&k);
 if(n>k)printf("%d",n-k);
 else
 {
  node tot;
  tot.cnt=0,tot.num=n;
  q.push(tot);
  vis[n]=true;
  while(!q.empty())
  {
   node u=q.front();
   q.pop();
   if(u.num==k)
   {
    printf("%d",u.cnt);
    return 0;
   }
   node v=u;
   v.cnt++;
   v.num++;
   if(v.num>=0&&v.num<=100000&&!vis[v.num])q.push(v),vis[v.num]=true;
   v.num-=2;
   if(v.num>=0&&v.num<=100000&&!vis[v.num])q.push(v),vis[v.num]=true;
   v.num++,v.num*=2;
   if(v.num>0&&v.num<=100000&&!vis[v.num])q.push(v),vis[v.num]=true;
  }
 }
 return 0;
}
