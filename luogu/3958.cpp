#include <cstdio>
#include <cmath>
struct point
{
 int x,y,z;
}p[1005];
int fa[1005];
double po(double x)
{
 return x*x;
}
double dist(double x1,double y1,double z1,double x2,double y2,double z2)
{
 return sqrt(po(x1-x2)+po(y1-y2)+po(z1-z2));
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[x]=y;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,h,r;
  scanf("%d%d%d",&n,&h,&r);
  for(int i=1;i<=n+2;i++)
   fa[i]=i;
  for(int i=1;i<=n;i++)
  {
   scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
   if(p[i].z<=r)unionn(find(i),find(n+1));
   if(p[i].z+r>=h)unionn(find(i),find(n+2));
  }
  for(int i=1;i<=n;i++)
   for(int j=1;j<i;j++)
   {
    if(dist(p[i].x,p[i].y,p[i].z,p[j].x,p[j].y,p[j].z)<=2*r)
     unionn(find(i),find(j));
   }
  if(find(n+1)==find(n+2))puts("Yes");
  else puts("No");
 }
 return 0;
}