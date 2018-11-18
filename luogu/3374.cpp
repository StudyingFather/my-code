#include <stdio.h>
int a[500005],n,m;
int lowbit(int x)
{
 return x&(-x);
}
void update(int x,int y)
{
 while(x<=n)
 {
  a[x]+=y;
  x+=lowbit(x);
 }
 return;
}
int query(int x)
{
 int ans=0;
 while(x)
 {
  ans+=a[x];
  x-=lowbit(x);
 }
 return ans;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  update(i,num);
 }
 for(int i=1;i<=m;i++)
 {
  int op,x,y;
  scanf("%d%d%d",&op,&x,&y);
  if(op==1)update(x,y);
  else printf("%d\n",query(y)-query(x-1));
 }
 return 0;
} 
