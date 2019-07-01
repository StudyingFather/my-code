#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
 int val,siz,randnum,son[2];
}a[100005];
int cnt,root;
void update(int x)
{
 a[x].siz=a[a[x].son[0]].siz+a[a[x].son[1]].siz+1;
}
void split_val(int root,int val,int&x,int&y)
{
 if(root==0)x=y=0;
 else
 {
  if(a[root].val<=val)
  {
   x=root;
   split_val(a[root].son[1],val,a[root].son[1],y);
  }
  else
  {
   y=root;
   split_val(a[root].son[0],val,x,a[root].son[0]);
  }
  update(root);
 }
}
void split_siz(int root,int siz,int&x,int&y)
{
 if(root==0)x=y=0;
 else
 {
  if(a[a[root].son[0]].siz>=siz)
  {
   y=root;
   split_siz(a[root].son[0],siz,x,a[root].son[0]);
  }
  else
  {
   x=root;
   split_siz(a[root].son[1],siz-a[a[root].son[0]].siz-1,a[root].son[1],y);
  }
  update(root);
 }
}
int merge(int x,int y)
{
 if(x==0||y==0)return x+y;
 int root;
 if(a[x].randnum>=a[y].randnum)
 {
  root=x;
  a[x].son[1]=merge(a[x].son[1],y);
 }
 else
 {
  root=y;
  a[y].son[0]=merge(x,a[y].son[0]);
 }
 update(root);
 return root;
}
int newnode(int val)
{
 a[++cnt].val=val;
 a[cnt].randnum=rand();
 a[cnt].siz=1;
 return cnt;
}
void insert(int val)
{
 int x,y;
 split_val(root,val,x,y);
 root=merge(merge(x,newnode(val)),y);
}
void remove(int val)
{
 int x,y,z;
 split_val(root,val,x,y);
 split_val(x,val-1,x,z);
 z=merge(a[z].son[0],a[z].son[1]);
 root=merge(merge(x,z),y);
}
int query_rank(int val)
{
 int x,y;
 split_val(root,val-1,x,y);
 int ans=a[x].siz+1;
 root=merge(x,y);
 return ans;
}
int query_num(int val)
{
 int x,y,z;
 split_siz(root,val,x,y);
 split_siz(x,val-1,x,z);
 root=merge(merge(x,z),y);
 return a[z].val;
}
int query_pre(int val)
{
 int x,y;
 split_val(root,val-1,x,y);
 int p=x;
 while(a[p].son[1])
  p=a[p].son[1];
 root=merge(x,y);
 return a[p].val;
}
int query_post(int val)
{
 int x,y;
 split_val(root,val,x,y);
 int p=y;
 while(a[p].son[0])
  p=a[p].son[0];
 root=merge(x,y);
 return a[p].val;
}
int main()
{
 int n;
 scanf("%d",&n);
 srand(n);
 while(n--)
 {
  int op,x;
  scanf("%d%d",&op,&x);
  if(op==1)insert(x);
  else if(op==2)remove(x);
  else if(op==3)printf("%d\n",query_rank(x));
  else if(op==4)printf("%d\n",query_num(x));
  else if(op==5)printf("%d\n",query_pre(x));
  else if(op==6)printf("%d\n",query_post(x));
 }
 return 0;
}