#include <cstdio>
struct Splay
{
 struct node
 {
  int fa,son[2],val,siz,cnt;
 }p[2000005];
 int root,tot;
 void pushup(int x)
 {
  p[x].siz=p[p[x].son[0]].siz+p[p[x].son[1]].siz+p[x].cnt;
 }
 int get(int x)
 {
  return x==p[p[x].fa].son[1];
 }
 void clear(int x)
 {
  p[x].fa=p[x].son[0]=p[x].son[1]=p[x].val=p[x].siz=p[x].cnt=0;
 }
 int getval(int x)
 {
  return p[x].val;
 }
 int pre()
 {
  int u=p[root].son[0];
  while(p[u].son[1])
   u=p[u].son[1];
  splay(u);
  return u;
 }
 int post()
 {
  int u=p[root].son[1];
  while(p[u].son[0])
   u=p[u].son[0];
  splay(u);
  return u;
 }
 void rotate(int x)
 {
  int y=p[x].fa,z=p[y].fa,c=get(x);
  p[y].son[c]=p[x].son[c^1];
  p[p[x].son[c^1]].fa=y;
  p[x].son[c^1]=y;
  p[y].fa=x;
  p[x].fa=z;
  if(z)p[z].son[y==p[z].son[1]]=x;
  pushup(x),pushup(y);
 }
 void splay(int x)
 {
  for(int f;(f=p[x].fa)!=0;rotate(x))
   if(p[f].fa)rotate(get(f)==get(x)?f:x);
  root=x;
 }
 int rank(int x)
 {
  int ans=0,u=root;
  while(1)
  {
   if(x<p[u].val)
    u=p[u].son[0];
   else
   {
    ans+=p[p[u].son[0]].siz;
    if(x==p[u].val)
    {
     splay(u);
     return ans+1;
    }
    else ans+=p[u].cnt,u=p[u].son[1];
   }
  }
 }
 int kth(int x)
 {
  int u=root;
  while(1)
  {
   if(p[u].son[0]&&x<=p[p[u].son[0]].siz)
    u=p[u].son[0];
   else
   {
    x-=p[u].cnt+p[p[u].son[0]].siz;
    if(x<=0)
    {
     splay(u);
     return p[u].val;
    }
    u=p[u].son[1];
   }
  }
 }
 void add(int x)
 {
  if(!root)
  {
   p[++tot].val=x;
   p[tot].cnt++;
   root=tot;
   pushup(root);
   return;
  }
  int u=root,f=0;
  while(1)
  {
   if(p[u].val==x)
   {
    p[u].cnt++;
    pushup(u),pushup(f);
    splay(u);
    return;
   }
   f=u;
   u=p[u].son[x>p[u].val];
   if(!u)
   {
    p[++tot].val=x;
    p[tot].cnt++;
    p[tot].fa=f;
    p[f].son[x>p[f].val]=tot;
    pushup(tot),pushup(f);
    splay(tot);
    return;
   }
  }
 }
 void del(int x)
 {
  rank(x);
  if(p[root].cnt>1)
  {
   p[root].cnt--;
   pushup(root);
   return;
  }
  else if(!p[root].son[0]&&!p[root].son[1])
  {
   clear(root);
   root=0;
   return;
  }
  else if(!p[root].son[1])
  {
   int u=root;
   root=p[root].son[0];
   p[root].fa=0;
   clear(u);
   return;
  }
  else if(!p[root].son[0])
  {
   int u=root;
   root=p[root].son[1];
   p[root].fa=0;
   clear(u);
   return;
  }
  else
  {
   int v=root;
   int u=pre();
   splay(u);
   p[p[v].son[1]].fa=u;
   p[u].son[1]=p[v].son[1];
   clear(v);
   pushup(root);
  }
 }
}tr;
int main()
{
 int n,m,lans=0,ans=0;
 scanf("%d%d",&n,&m);
 while(n--)
 {
  int x;
  scanf("%d",&x);
  tr.add(x);
 }
 while(m--)
 {
  int op,x;
  scanf("%d%d",&op,&x);
  x^=lans;
  if(op==1)tr.add(x);
  else if(op==2)tr.del(x);
  else if(op==3)
  {
   tr.add(x);
   lans=tr.rank(x);
   ans^=lans;
   tr.del(x);
  }
  else if(op==4)
  {
   lans=tr.kth(x);
   ans^=lans;
  }
  else if(op==5)
  {
   tr.add(x);
   lans=tr.getval(tr.pre());
   ans^=lans;
   tr.del(x);
  }
  else
  {
   tr.add(x);
   lans=tr.getval(tr.post());
   ans^=lans;
   tr.del(x);
  }
 }
 printf("%d\n",ans);
 return 0;
}