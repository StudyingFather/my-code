/*
 Name: Kick Start 2019 Round E Problem A
 Author: StudyingFather
 Date: 2019/08/31 23:35
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int fa[100005];
int find(int x)
{
 return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  int n,m,cnt=0;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
   fa[i]=i;
  while(m--)
  {
   int x,y;
   scanf("%d%d",&x,&y);
   if(find(x)!=find(y))
    unionn(find(x),find(y)),cnt++;
  }
  printf("Case #%d: %d\n",kase,cnt+(n-cnt-1)*2);
 }
 return 0;
}