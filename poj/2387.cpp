#include <stdio.h>
int n,m,cnt;
int d[10005],heads[10005],q[10005],head,tail;
bool viss[10005];
struct node
{
 int v;
 int next;
 int val;
}edge[10005];
void add(int x,int y,int z)
{
 edge[++cnt].v=y;
 edge[cnt].next=heads[x];
 edge[cnt].val=z;
 heads[x]=cnt;
}
void spfa()
{
 head=1;tail=2;
 q[1]=1;
 viss[1]=1;
 while(head<tail)
 {
  int i;
  for(i=heads[q[head]];i!=0;i=edge[i].next)
  {
   if(d[q[head]]+edge[i].val<d[edge[i].v])
   {
    d[edge[i].v]=d[q[head]]+edge[i].val;
    if(!viss[edge[i].v])
    {
     q[tail++]=edge[i].v;
     viss[edge[i].v]=1;
    }
   }
  }
  viss[q[head]]=0;
  head++;
 }
}
int main()
{
 scanf("%d%d",&m,&n);
 int i;
 for(i=2;i<=n;i++)
  d[i]=214748364;
 int x,y,z;
 for(i=1;i<=m;i++)
 {
  scanf("%d%d%d",&x,&y,&z);
  add(x,y,z);
  add(y,x,z);
 }
 spfa();
 printf("%d",d[n]);
 return 0;
}
