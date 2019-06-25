#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int tx[]={1,-1,0,0};
const int ty[]={0,0,1,-1};
struct node
{
 int x,y,t1,t2;
};
int n,m,p,s[15],cnt,used[15];
char ma[1005][1005];
vector<queue<node> > q;
queue<node> que;
int main()
{
 scanf("%d%d%d",&n,&m,&p);
 for(int i=1;i<=p;i++)
  scanf("%d",&s[i]);
 for(int i=1;i<=n;i++)
  scanf("%s",ma[i]+1);
 cnt=n*m;
 for(int i=1;i<=p+1;i++)
  q.push_back(que);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if(ma[i][j]=='#')cnt--;
   else if(ma[i][j]>='1'&&ma[i][j]<='9')
   {
    ma[i][j]-='0';
    q[ma[i][j]].push({i,j,0,0});
    used[ma[i][j]]++;
    cnt--;
   }
 int cur=1,t=0;
 while(cnt)
 {
  while(!q[cur].empty())
  {
   node x=q[cur].front();
   if(x.t2==s[cur]&&x.t1==t)break;
   if(x.t1>t)break;
   for(int i=0;i<=3;i++)
    if(ma[x.x+tx[i]][x.y+ty[i]]=='.')
    {
     q[cur].push({x.x+tx[i],x.y+ty[i],x.t1!=t&&x.t2!=0?x.t1+1:x.t1,x.t1!=t&&x.t2!=0?1:x.t2+1});
     ma[x.x+tx[i]][x.y+ty[i]]=cur;
     used[cur]++;
     cnt--;
    }
   q[cur].pop();
   if(!cnt)break;
  }
  cur++;
  if(cur>p)
  {
   cur=1;
   t++;
  }
 }
 for(int i=1;i<=p;i++)
  printf("%d ",used[i]);
 puts("");
 return 0;
}