#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 2147483647
using namespace std;
struct treap
{
 int son[2],size,val,pri,cnt;
}t[2000005];
int root,cnt;
void pushup(int p)
{
 t[p].size=t[t[p].son[0]].size+t[t[p].son[1]].size+t[p].cnt;
}
void rotate(int &p,int d)
{
 int k=t[p].son[d^1];
 t[p].son[d^1]=t[k].son[d];
 t[k].son[d]=p;
 pushup(p);
 pushup(k);
 p=k;
}
void insert(int &p,int x)
{
 if(!p)
 {
  p=++cnt;
  t[p].son[0]=t[p].son[1]=0;
  t[p].size=1;
  t[p].val=x;
  t[p].pri=rand();
  t[p].cnt=1;
  return;
 }
 if(x==t[p].val)t[p].cnt++,t[p].size++;
 else
 {
  int d=0;
  if(x>t[p].val)d=1;
  insert(t[p].son[d],x);
  if(t[p].pri<t[t[p].son[d]].pri)rotate(p,d^1);
 }
 pushup(p);
}
void del(int &p,int x)
{
 if(!p)return;
 if(x==t[p].val)
 {
  if((!t[p].son[0])&&(!t[p].son[1]))
  {
   t[p].size--;
   t[p].cnt--;
   if(!t[p].cnt)p=0;
  }
  else if(t[p].son[0]&&(!t[p].son[1]))
  {
   rotate(p,1);
   del(t[p].son[1],x);
  }
  else if((!t[p].son[0])&&t[p].son[1])
  {
   rotate(p,0);
   del(t[p].son[0],x);
  }
  else
  {
   int d=0;
   if(t[t[p].son[0]].pri>t[t[p].son[1]].pri)d=1;
   rotate(p,d);
   del(t[p].son[d],x);
  }
 }
 else if(x<t[p].val)del(t[p].son[0],x);
 else del(t[p].son[1],x);
 pushup(p);
}
int query_rank(int &p,int x)
{
 if(!p)return 0;
 if(t[p].val==x)return t[t[p].son[0]].size+1;
 else if(t[p].val<x)
  return t[t[p].son[0]].size+t[p].cnt+query_rank(t[p].son[1],x);
 else return query_rank(t[p].son[0],x);
}
int query_num(int &p,int x)
{
 if(!p)return 0;
 if(t[t[p].son[0]].size>=x)return query_num(t[p].son[0],x);
 else if(t[t[p].son[0]].size+t[p].cnt<x)
  return query_num(t[p].son[1],x-t[p].cnt-t[t[p].son[0]].size);
 else return t[p].val;
}
int query_pre(int &p,int x)
{
 if(!p)return -INF;
 if(t[p].val>=x)return query_pre(t[p].son[0],x);
 else return max(t[p].val,query_pre(t[p].son[1],x));
}
int query_post(int &p,int x)
{
 if(!p)return INF;
 if(t[p].val<=x)return query_post(t[p].son[1],x);
 else return min(t[p].val,query_post(t[p].son[0],x));
}
int main()
{
 int n,m,lans=0,ans=0;
 scanf("%d%d",&n,&m);
 srand(n);
 while(n--)
 {
  int x;
  scanf("%d",&x);
  insert(root,x);
 }
 while(m--)
 {
  int op,x;
  scanf("%d%d",&op,&x);
  x^=lans;
  if(op==1)insert(root,x);
  else if(op==2)del(root,x);
  else if(op==3)
  {
   insert(root,x);
   ans^=(lans=query_rank(root,x));
   del(root,x);
  }
  else if(op==4)
   ans^=(lans=query_num(root,x));
  else if(op==5)
   ans^=(lans=query_pre(root,x));
  else if(op==6)
   ans^=(lans=query_post(root,x));
 }
 printf("%d\n",ans);
 return 0;
}