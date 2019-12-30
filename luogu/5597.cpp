#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
int ans=1e8;
struct tree
{
 struct node
 {
  int son[2];
 }tr[100005];
 int cnt,rt;
 void clear()
 {
  memset(tr,0,sizeof(tr));
  cnt=1,rt=1;
 }
}p,q;
char s[2005];
int path[2005],dfn;
void build(int& u)
{
 if(!u)u=++p.cnt;
 int x=s[dfn++];
 if(x&1)build(p.tr[u].son[0]);
 if(x&2)build(p.tr[u].son[1]);
}
void merge(int& x,int y,int z)
{
 if(!x)x=++q.cnt;
 if(y==z)return;
 if(p.tr[y].son[0])merge(q.tr[x].son[0],p.tr[y].son[0],z);
 if(p.tr[y].son[1])merge(q.tr[x].son[1],p.tr[y].son[1],z);
}
void dfs(int u,int d)
{
 if(!u)return;
 if(u!=1)
 {
  q.clear();
  int x=1;
  while(x)
  {
   int r=x;
   for(int i=0;i<d;i++)
    x=p.tr[x].son[path[i]];
   merge(q.rt,r,x);
  }
  ans=min(ans,(q.cnt-1)*2-d);
 }
 path[d]=0;
 dfs(p.tr[u].son[0],d+1);
 path[d]=1;
 dfs(p.tr[u].son[1],d+1);
}
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  s[i]-='0';
 p.clear(),q.clear();
 build(p.rt);
 dfs(p.rt,0);
 printf("%d\n",ans);
 return 0;
}