#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct trie
{
 int son[35],end;
}tr[100005];
int vis[2000005],cnt;
char s[2000005];
void add()
{
 int len=strlen(s),pos=0;
 for(int i=0;i<len;i++)
 {
  if(!tr[pos].son[s[i]-'a'])tr[pos].son[s[i]-'a']=++cnt;
  pos=tr[pos].son[s[i]-'a'];
 }
 tr[pos].end=1;
}
int find()
{
 int ans=0,pos=0,len=strlen(s);
 memset(vis,0,sizeof(vis));
 for(int i=0;i<len;i++)
 {
  pos=tr[pos].son[s[i]-'a'];
  if(!pos)break;
  if(tr[pos].end)vis[i]=1;
 }
 for(int i=0;i<len;i++)
  if(vis[i])
  {
   pos=0;
   ans=i+1;
   for(int j=i+1;j<len;j++)
   {
    pos=tr[pos].son[s[j]-'a'];
    if(!pos)break;
    if(tr[pos].end)vis[j]=1;
   }
  }
 return ans;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s);
  add();
 }
 for(int i=1;i<=m;i++)
 {
  scanf("%s",s);
  printf("%d\n",find());
 }
 return 0;
}