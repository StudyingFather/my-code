/*
 Name: luogu P5543
 Author: StudyingFather
 Date: 2019/10/08 22:02
 Website: https://studyingfather.com
*/
#include <cstdio>
char s[5];
int fa[200005],t[200005];
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[find(y)]=find(x);
}
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=2*n;i++)
  fa[i]=i;
 while(m--)
 {
  int x,y;
  scanf("%s",s);
  scanf("%d%d",&x,&y);
  if(s[0]=='S')
   unionn(x,y),unionn(x+n,y+n);
  else
   unionn(x,y+n),unionn(x+n,y);
 }
 for(int i=1;i<=n;i++)
 {
  int x=find(i),y=find(i+n);
  if(x==y)
  {
   ans=-1;
   break;
  }
  if(!t[x]&&x<=n)ans++,t[x]++;
 }
 if(ans==-1)puts("0");
 else
 {
  putchar('1');
  while(ans)
   putchar('0'),ans--;
 }
 return 0;
}