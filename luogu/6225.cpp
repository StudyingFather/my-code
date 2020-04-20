#include <cstdio>
int n,q,a[200005],b[2][200005];
int lowbit(int x)
{
 return x&(-x);
}
void add(int x,int pos,int q)
{
 while(pos<=n)
 {
  b[q][pos]^=x;
  pos+=lowbit(pos);
 }
}
int query(int pos,int q)
{
 int ans=0;
 while(pos)
 {
  ans^=b[q][pos];
  pos-=lowbit(pos);
 }
 return ans;
}
int main()
{
 scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  add(a[i],i,i&1);
 }
 while(q--)
 {
  int op,x,y;
  scanf("%d%d%d",&op,&x,&y);
  if(op==1)add(a[x],x,x&1),add(a[x]=y,x,x&1);
  else
  {
   if((x+y)&1)puts("0");
   else printf("%d\n",query(y,x&1)^query(x-1,x&1));
  }
 }
 return 0;
}