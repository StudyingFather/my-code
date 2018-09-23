#include <stdio.h>
int n,m,x,y;
struct node
{
 int x1,y1,x2,y2;
}a[2005];
int main()
{
 scanf("%d%d",&m,&n);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  int ans=0,last=0;
  for(int j=1;j<=m;j++)
   if(x>=a[j].x1&&x<=a[j].x2&&y>=a[j].y1&&y<=a[j].y2)
   {
   	ans++;
   	last=j;
   }
  if(!ans)printf("NO\n");
  else printf("YES %d %d\n",ans,last);
 }
 return 0;
}
