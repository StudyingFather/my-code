#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
 int x,y;
}p[15];
int main()
{
 int s1,s2,sj1,sj2;
 for(int i=1;i<=6;i++)
  scanf("%d %d",&p[i].x,&p[i].y);
 s1=(p[2].x-p[1].x)*(p[2].y-p[1].y);
 s2=(p[4].x-p[3].x)*(p[4].y-p[3].y);
 if(p[5].x>=p[2].x||p[5].y>=p[2].y||p[6].x<=p[1].x||p[6].y<=p[1].y)sj1=0;//不相交
 else sj1=(min(p[6].x,p[2].x)-max(p[5].x,p[1].x))*(min(p[6].y,p[2].y)-max(p[5].y,p[1].y));
 if(p[5].x>=p[4].x||p[5].y>=p[4].y||p[6].x<=p[3].x||p[6].y<=p[3].y)sj2=0;
 else sj2=(min(p[6].x,p[4].x)-max(p[5].x,p[3].x))*(min(p[6].y,p[4].y)-max(p[5].y,p[3].y));
 printf("%d",s1+s2-sj1-sj2);
 return 0;
}
