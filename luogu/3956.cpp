//考场上写的代码，所以有些丑
//各位dalao见谅
//注释是考完以后添加的
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3fffffff
using namespace std;
int m,n,map[105][105],cost[105][105];
struct zt
{
 int x,y,is_cc,money;
 //is_cc=is_changed_color，代表该格是否变过颜色
 //0代表没有变色（即该格本身有颜色）
 //其他数字表示该格由白色变为相应的颜色 
}que[100005];
int h=1,t=1;
void push(int x,int y,int is_cc,int money)//入队 
{
 que[t].x=x;
 que[t].y=y;
 que[t].is_cc=is_cc;
 que[t].money=money;
 t++;
}
void pop()//出队 
{
 h++;
}
int is_empty()//判空 
{
 return h==t;
}
void init()
{
 scanf("%d%d",&m,&n);
 for(int i=1;i<=m;i++)
  for(int j=1;j<=m;j++)
   cost[i][j]=INF;
 for(int i=1;i<=n;i++)
 {
  int x,y,c;
  scanf("%d%d%d",&x,&y,&c);
  map[x][y]=c+1;
  //颜色参数：0---无色，1---红色，2---黄色 
 }
}
int main()
{
 init();
 push(1,1,0,0);
 cost[1][1]=0;
 for(int i=1;!is_empty();i++)//广搜，貌似h并没有什么卵用 
 { 
  int x=que[i].x,y=que[i].y,is_cc=que[i].is_cc,money=que[i].money;
  if(money>cost[x][y])continue;//剪枝
  if(x!=m&&((is_cc&&map[x+1][y])||(!is_cc)))//向下
  //is_cc&&map[x+1][y]代表当前格为白色，且要扩展的格有颜色（不能连续走过两个白色格）
  //!is_cc代表该格没变颜色（即不是白色格），可以任意扩展。 
  {
   if((!map[x+1][y]))//白色格
   {
    if(money+2<cost[x+1][y])
    {
     push(x+1,y,map[x][y],money+2);//显然，将白色格变为与当前格颜色相同的格子可以节省开支
     cost[x+1][y]=money+2;//更新最优解
    }
   }
   else if((is_cc?is_cc:map[x][y])!=map[x+1][y])//不同颜色格
   {
    if(money+1<cost[x+1][y])
    {
     push(x+1,y,0,money+1);
     cost[x+1][y]=money+1;
    }
   }
   else//相同颜色格
   {
    if(money<cost[x+1][y])
    {
     push(x+1,y,0,money);
     cost[x+1][y]=money;
    }
   }
  }
  //以下代码结构与上面相同
  //没错，为了偷懒，考场上直接Ctrl+C，Ctrl+V了
  //并且因此出现了不少麻烦的事情
  //所以，请各位dalao不要在考场上学我这样作死
  if(x!=1&&((is_cc&&map[x-1][y])||(!is_cc)))//向上 
  {
   if((!map[x-1][y]))
   {
    if(money+2<cost[x-1][y])
    {
     push(x-1,y,map[x][y],money+2);
     cost[x-1][y]=money+2;
    }
   }
   else if((is_cc?is_cc:map[x][y])!=map[x-1][y])
   {
    if(money+1<cost[x-1][y])
    {
     push(x-1,y,0,money+1);
     cost[x-1][y]=money+1;
    }
   }
   else
   {
    if(money<cost[x-1][y])
    {
     push(x-1,y,0,money);
     cost[x-1][y]=money;
    }
   }
  }
  if(y!=m&&((is_cc&&map[x][y+1])||(!is_cc)))//向右 
  {
   if((!map[x][y+1]))
   {
    if(money+2<cost[x][y+1])
    {
     push(x,y+1,map[x][y],money+2);
     cost[x][y+1]=money+2;
    }
   }
   else if((is_cc?is_cc:map[x][y])!=map[x][y+1])
   {
    if(money+1<cost[x][y+1])
    {
     push(x,y+1,0,money+1);
     cost[x][y+1]=money+1;
    }
   }
   else 
   {
    if(money<cost[x][y+1])
    {
     push(x,y+1,0,money);
     cost[x][y+1]=money;
    }
   }
  }
  if(y!=1&&((is_cc&&map[x][y-1])||(!is_cc)))//向左 
  {
   if((!map[x][y-1]))
   {
    if(money+2<cost[x][y-1])
    {
     push(x,y-1,map[x][y],money+2);
     cost[x][y-1]=money+2;
    }
   }
   else if((is_cc?is_cc:map[x][y])!=map[x][y-1])
   {
    if(money+1<cost[x][y-1])
    {
     push(x,y-1,0,money+1);
     cost[x][y-1]=money+1;
    }
   }
   else
   {
    if(money<cost[x][y-1])
    {
     push(x,y-1,0,money);
     cost[x][y-1]=money;
    }
   }
  }
  pop();
 }
 if(cost[m][m]!=INF)printf("%d",cost[m][m]);
 else printf("-1");
 return 0;
}
