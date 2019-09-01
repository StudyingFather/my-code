/*
 Name: luogu P1560
 Author: StudyingFather
 Date: 2019/08/24 19:16
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int ma[125][125],ans,n,b;
char s[5];
bool access(int x,int y)
{
 return x>0&&x<=n&&y>0&&y<=n&&ma[x][y]!=-1;
}
void dfs(int x,int y,int dir,int cnt)
{
 if(ma[x][y]==1)return;
 ans=max(ans,cnt);
 ma[x][y]=1;
 if(access(x+dx[dir],y+dy[dir]))dfs(x+dx[dir],y+dy[dir],dir,cnt+1);
 else
 {
  if(dir>=2)
  {
   if(access(x+dx[0],y+dy[0]))dfs(x+dx[0],y+dy[0],0,cnt+1);
   if(access(x+dx[1],y+dy[1]))dfs(x+dx[1],y+dy[1],1,cnt+1);
  }
  else
  {
   if(access(x+dx[2],y+dy[2]))dfs(x+dx[2],y+dy[2],2,cnt+1);
   if(access(x+dx[3],y+dy[3]))dfs(x+dx[3],y+dy[3],3,cnt+1);
  }
 }
 ma[x][y]=0;
}
int main()
{
 scanf("%d%d",&n,&b);
 for(int i=1;i<=b;i++)
 {
  scanf("%s",s);
  int num=0,len=strlen(s);
  for(int i=1;i<len;i++)
   num=num*10+s[i]-'0';
  ma[s[0]-'A'+1][num]=-1;
 }
 dfs(1,1,0,1);
 dfs(1,1,2,1);
 printf("%d\n",ans);
 return 0;
}