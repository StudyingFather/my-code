#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int x,y,step;
};
struct ans
{
 int x,y;
}last[5][5];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1}; 
int map[5][5],f[5][5];
queue <node> q;
void print(int x,int y)
{
 if(x==-1&&y==-1)return;
 print(last[x][y].x,last[x][y].y);
 printf("(%d, %d)\n",x,y);
}
int main()
{
 for(int i=0;i<5;i++)
  for(int j=0;j<5;j++)
   scanf("%d",&map[i][j]);
 memset(f,1,sizeof(f));
 node tot;
 tot.x=tot.y=0,tot.step=1;
 last[0][0].x=last[0][0].y=-1,f[0][0]=1;
 q.push(tot);
 while(!q.empty())
 {
  node tmp=q.front();
  q.pop();
  if(tmp.x==4&&tmp.y==4)break; 
  for(int i=0;i<4;i++)
  {
   node next=tmp;
   next.x+=dx[i],next.y+=dy[i],next.step++;
   if(next.x<0||next.x>4||next.y<0||next.y>4)continue;
   if(next.x==last[tmp.x][tmp.y].x&&next.y==last[tmp.x][tmp.y].y)continue;
   if(next.step>f[next.x][next.y])continue;
   if(!map[next.x][next.y])
   {
    f[next.x][next.y]=next.step;
    last[next.x][next.y].x=tmp.x;
    last[next.x][next.y].y=tmp.y;
    q.push(next);
   }
  }
 }
 print(4,4);
 return 0;
}
