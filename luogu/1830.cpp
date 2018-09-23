#include <stdio.h>
int n,m,x,y;
struct node
{
 int x1,y1,x2,y2;
}a[105];
int main()
{
 scanf("%d%d%d%d",&n,&m,&x,&y);
 for(int i=1;i<=x;i++)
  scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
 for(int i=1;i<=y;i++)
 {
  int m,n;
  scanf("%d%d",&m,&n);
  int ans=0,last=0;
  for(int j=1;j<=x;j++)
   if(m>=a[j].x1&&m<=a[j].x2&&n>=a[j].y1&&n<=a[j].y2)
   {
   	ans++;
   	last=j;
   }
  if(!ans)printf("N\n");
  else printf("Y %d %d\n",ans,last);
 }
 return 0;
}
