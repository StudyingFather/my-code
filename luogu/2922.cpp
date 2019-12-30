#include <cstdio>
const int sig=2;
struct trie
{
 struct node
 {
  int son[sig],sum,end;
 }tr[500005];
 int cnt;
 void insert(int* a,int l)
 {
  int u=0;
  for(int i=1;i<=l;i++)
  {
   int &nxt=tr[u].son[a[i]];
   if(!nxt)
    nxt=++cnt;
   u=nxt,tr[u].sum++;
  }
  tr[u].end++;
 }
 int find(int* a,int l)
 {
  int ans=0,u=0;
  for(int i=1;i<=l;i++)
  {
   int nxt=tr[u].son[a[i]];
   if(!nxt)return ans;
   u=nxt;
   ans+=tr[u].end;
  }
  return ans+tr[u].sum-tr[u].end;
 }
}t;
int a[500005];
int main()
{
 int m,n;
 scanf("%d%d",&m,&n);
 while(m--)
 {
  int l;
  scanf("%d",&l);
  for(int i=1;i<=l;i++)
   scanf("%d",&a[i]);
  t.insert(a,l);
 }
 while(n--)
 {
  int l;
  scanf("%d",&l);
  for(int i=1;i<=l;i++)
   scanf("%d",&a[i]);
  printf("%d\n",t.find(a,l));
 }
 return 0;
}