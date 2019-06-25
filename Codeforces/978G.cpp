#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct exam
{
 int s,d,c,id,cha;
}e[105];
int pre[105],ans[105],flag[105];
struct cmp1
{
 bool operator()(const exam&a,const exam&b)const
 {
  return a.d>b.d;
 }
};
struct cmp2
{
 bool operator()(const exam&a,const exam&b)const
 {
  return a.cha<b.cha||(a.cha==b.cha&&a.s<b.s);
 }
};
priority_queue<exam,vector<exam>,cmp1> q1;
priority_queue<exam,vector<exam>,cmp2> q2;
int n,m;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  scanf("%d%d%d",&e[i].s,&e[i].d,&e[i].c);
  e[i].id=i;
  e[i].cha=e[i].d-e[i].s;
  if(e[i].cha<e[i].c)
  {
   printf("-1");
   return 0;
  }
  q1.push(e[i]);
  q2.push(e[i]);
 }
 for(int i=1;i<=n;i++)
 {
  int end=0;
  if(q1.empty()||q2.empty())continue;
  exam tp1=q1.top();
  exam tp2=q2.top();
  while(flag[tp1.id])
  {
   q1.pop();
   if(q1.empty())
   {
    end=1;
    break;
   }
   tp1=q1.top();
  }
  while(flag[tp2.id])
  {
   q2.pop();
   if(q2.empty())
   {
    end=1;
    break;
   }
   tp2=q2.top();
  }
  if(end)break;
  if(tp1.d==i)//¿¼ÊÔÊ±¼äµ½
  {
   if(pre[tp1.id]==tp1.c)
   {
    ans[i]=m+1;
    flag[tp1.id]=1;
    q1.pop();
   }
   else
   {
    printf("-1");
    return 0;
   }
  }
  else if(tp2.s>i)continue;
  else
  {
   if(pre[tp2.id]<tp2.c)
   {
    ans[i]=tp2.id;
    pre[tp2.id]++;
   }
   else
   {
    ans[tp2.d]=m+1;
    flag[tp2.id]=1;
    q2.pop();
    tp2=q2.top();
    if(tp2.s>i)continue;
    ans[i]=tp2.id;
    pre[tp2.id]++;
   }
  }
 }
 for(int i=1;i<=n;i++)
  printf("%d ",ans[i]);
 return 0;
}
