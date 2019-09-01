/*
 Name: luogu P1801
 Author: StudyingFather
 Date: 2019/08/02 20:36
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node
{
 int son[2],val,siz,pri,cnt;
}tr[200005];
int a[200005],b[200005],root,cnt;
void pushup(int p)
{
 tr[p].siz=tr[tr[p].son[0]].siz+tr[tr[p].son[1]].siz+tr[p].cnt;
}
void rotate(int &p,int d)
{
 int k=tr[p].son[d^1];
 tr[p].son[d^1]=tr[k].son[d];
 tr[k].son[d]=p;
 pushup(p);
 pushup(k);
 p=k;
}
void add(int &p,int x)
{
 if(!p)
 {
  p=++cnt;
  tr[p].son[0]=tr[p].son[1]=0;
  tr[p].val=x;
  tr[p].siz=1;
  tr[p].pri=rand();
  tr[p].cnt=1;
  return;
 }
 if(x==tr[p].val)tr[p].cnt++,tr[p].siz++;
 else
 {
  int d=0;
  if(x>tr[p].val)d=1;
  add(tr[p].son[d],x);
  if(tr[tr[p].son[d]].pri>tr[p].pri)rotate(p,d^1);
 }
 pushup(p);
}
int query_num(int &p,int x)
{
 if(!p)return 0;
 if(tr[tr[p].son[0]].siz>=x)return query_num(tr[p].son[0],x);
 else if(tr[tr[p].son[0]].siz+tr[p].cnt<x)
  return query_num(tr[p].son[1],x-tr[p].cnt-tr[tr[p].son[0]].siz);
 else return tr[p].val;
}
int main()
{
 srand(time(NULL));
 int m,n;
 scanf("%d%d",&m,&n);
 for(int i=1;i<=m;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 b[n+1]=m+1;
 int cur=1;
 for(int i=1;i<=m;i++)
 {
  add(root,a[i]);
  while(i==b[cur])
  {
   printf("%d\n",query_num(root,cur));
   cur++;
  }
 }
 return 0;
}