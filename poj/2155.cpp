#include <stdio.h>
#include <string.h>
int sum[1005][1005],n;
int lowbit(int x)
{
 return x&(-x);
}
void change(int x,int y)
{
 int ty=y;
 while(x<=n)
 {
  y=ty;
  while(y<=n)
  {
   sum[x][y]^=1;
   y+=lowbit(y);
  }
  x+=lowbit(x);
 }
}
int query(int x,int y)
{
 int ty=y,ans=0;
 while(x>0)
 {
  y=ty;
  while(y>0)
  {
   ans+=sum[x][y];
   y-=lowbit(y);
  }
  x-=lowbit(x);
 }
 return ans;
}
int main()
{
 int T,t;
 scanf("%d",&T);
 while(T--)
 {
  scanf("%d%d",&n,&t);
  memset(sum,0,sizeof(sum));
  for(int i=1;i<=t;i++)
  {
   int x1,x2,y1,y2;
   char c[3];
   scanf("%s",c);
   if(c[0]=='C')
   {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    change(x1,y1);
    change(x1,y2+1);
    change(x2+1,y1);
    change(x2+1,y2+1);
   }
   else
   {
    scanf("%d%d",&x1,&y1);
    printf("%d\n",query(x1,y1)&1);
   }
  }
  if(T)printf("\n");
 }
 return 0;
}
