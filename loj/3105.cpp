// Problem: #3105. 「TJOI2019」甲苯先生的滚榜
// Contest: LibreOJ
// URL: https://loj.ac/problem/3105
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
typedef unsigned ui;
struct pii
{
 int x,y;
 bool operator<(const pii&a)const
 {
  return x<a.x||(x==a.x&&y>a.y);
 }
 bool operator==(const pii&a)const
 {
  return x==a.x&&y==a.y;
 }
 bool operator>(const pii&a)const
 {
  return !(*this<a)&&!(*this==a);
 }
};
struct treap
{
 int son[1000005][2],cnt[1000005],siz[1000005],pri[1000005];
 int tot,rt;
 pii val[1000005];
 void init()
 {
  rt=0,tot=0;
 }
 void pushup(int u)
 {
  siz[u]=siz[son[u][0]]+siz[son[u][1]]+cnt[u];
 }
 void rotate(int &u,int d)
 {
  int k=son[u][d^1];
  son[u][d^1]=son[k][d];
  son[k][d]=u;
  pushup(u);
  pushup(k);
  u=k;
 }
 void insert(int &u,pii x)
 {
  if(!u)
  {
   u=++tot;
   val[u]=x;
   cnt[u]=siz[u]=1;
   pri[u]=rand();
   son[u][0]=son[u][1]=0;
   return;
  }
  if(x==val[u])cnt[u]++;
  else
  {
   int d=(x>val[u]);
   insert(son[u][d],x);
   if(pri[u]<pri[son[u][d]])rotate(u,d^1);
  }
  pushup(u);
 }
 void del(int &u,pii x)
 {
  if(!u)return;
  if(x==val[u])
  {
   if(!son[u][0]&&!son[u][1])
   {
    siz[u]--,cnt[u]--;
    if(!cnt[u])u=0;
   }
   else if(son[u][0]&&!son[u][1])
   {
    rotate(u,1);
    del(son[u][1],x);
   }
   else if(!son[u][0]&&son[u][1])
   {
    rotate(u,0);
    del(son[u][0],x);
   }
   else
   {
    int d=(pri[son[u][0]]>pri[son[u][1]]);
    rotate(u,d);
    del(son[u][d],x);
   }
  }
  else if(x<val[u])del(son[u][0],x);
  else del(son[u][1],x);
  pushup(u);
 }
 int rank(int u,pii x)
 {
  if(!u)return 0;
  else if(x==val[u])return siz[son[u][1]];
  else if(x<val[u])return siz[son[u][1]]+cnt[u]+rank(son[u][0],x);
  else return rank(son[u][1],x);
 }
}tr;
pii ans[1000005];
ui randNext(ui &seed,ui last,ui m)
{ 
 seed=seed*17+last;
 return seed%m+1; 
}
int main()
{
 srand(time(NULL));
 int T,last=7;
 scanf("%d",&T);
 while(T--)
 {
  int m,n;
  tr.init();
  ui seed;
  scanf("%d%d%u",&m,&n,&seed);
  memset(ans,0,sizeof(ans));
  while(n--)
  {
   int ria=randNext(seed,last,m),rib=randNext(seed,last,m);
   if(ans[ria].x)tr.del(tr.rt,ans[ria]);
   ans[ria].x++,ans[ria].y+=rib;
   tr.insert(tr.rt,ans[ria]);
   printf("%d\n",last=tr.rank(tr.rt,ans[ria]));
  }
 }
 return 0;
}