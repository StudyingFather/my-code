#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dist[510][510];
char map[510][510];
bool proc[510][510];
pair<int,int>queue[1000005];
int r,c,li,ri;
bool valid(int x,int y)
{
 return x>=0&&x<=r&&y>=0&&y<=c;
}
void que_add(int x,int y,int v)
{
 if(dist[x][y]<0||v<dist[x][y])
 {
  dist[x][y]=v;
  if(li==ri||v>dist[queue[li].first][queue[li].second])queue[ri++]=make_pair(x,y);
  else queue[--li]=make_pair(x,y);
 }
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d%d",&r,&c);
  for(int i=0;i<r;i++)
   scanf("%s",map[i]);
  if((r+c)%2)puts("NO SOLUTION");//如果行数加列数为奇数，显然无解（可以画个图试试） 
  else
  {
   li=ri=500005;
   queue[ri++]=make_pair(0,0);
   memset(dist,-1,sizeof(dist));
   dist[0][0]=0;
   memset(proc,false,sizeof(proc));
   while(li!=ri)
   {
    int cx=queue[li].first,cy=queue[li].second;
    li++;
    if(valid(cx-1,cy-1))
    {
     if(map[cx-1][cy-1]=='\\')que_add(cx-1,cy-1,dist[cx][cy]);
     else que_add(cx-1,cy-1,dist[cx][cy]+1);
    }
    if(valid(cx-1,cy+1))
    {
     if(map[cx-1][cy]=='/')que_add(cx-1,cy+1,dist[cx][cy]);
     else que_add(cx-1,cy+1,dist[cx][cy]+1);
    }
    if(valid(cx+1,cy-1))
    {
     if(map[cx][cy-1]=='/')que_add(cx+1,cy-1,dist[cx][cy]);
     else que_add(cx+1,cy-1,dist[cx][cy]+1);
    }
    if(valid(cx+1,cy+1))
    {
     if(map[cx][cy]=='\\')que_add(cx+1,cy+1,dist[cx][cy]);
     else que_add(cx+1,cy+1,dist[cx][cy]+1);
    }
   }
   printf("%d\n",dist[r][c]);
  }
 }
 return 0;
}
