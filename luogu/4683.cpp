#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int sig=26;
char res[1000005];
int ans;
struct trie
{
 struct node
 {
  int son[sig],end,ls,dep,maxd;
 }tr[500005];
 int cnt;
 void insert(char* s)
 {
  int u=0;
  for(int i=0;s[i];i++)
  {
   int &v=tr[u].son[s[i]-'a'];
   if(!v)v=++cnt;
   u=v;
  }
  tr[u].end=1;
 }
 void dfs1(int u,int fa)
 {
  tr[u].maxd=tr[u].dep=tr[fa].dep+1;
  tr[u].ls=-1;
  for(int i=0;i<sig;i++)
  {
   int v=tr[u].son[i];
   if(v)
   {
    dfs1(v,u);
    if(tr[v].maxd>tr[u].maxd)
    {
     tr[u].maxd=tr[v].maxd;
     tr[u].ls=i;
    }
   }
  }
 }
 void dfs2(int u)
 {
  if(tr[u].end)res[++ans]='P';
  int ls=tr[u].ls;
  for(int i=0;i<sig;i++)
  {
   int v=tr[u].son[i];
   if(v&&i!=ls)
   {
    res[++ans]='a'+i;
    dfs2(v);
   }
  }
  if(ls!=-1)
  {
   res[++ans]='a'+ls;
   dfs2(tr[u].son[ls]);
  }
  res[++ans]='-';
 }
}t;
char s[25];
int main()
{
 int n;
 scanf("%d",&n);
 int maxl=0;
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s);
  maxl=max(maxl,(int)strlen(s));
  t.insert(s);
 }
 t.dfs1(0,0);
 t.dfs2(0);
 ans-=maxl+1;
 printf("%d\n",ans);
 for(int i=1;i<=ans;i++)
  printf("%c\n",res[i]);
 return 0;
}