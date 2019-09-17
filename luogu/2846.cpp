/*
 Name: luogu P2846
 Author: StudyingFather
 Date: 2019/09/17 12:27
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct seg
{
 int val,tag;
}a[800005];
int n,m;
void pushup(int root)
{
 a[root].val=a[root<<1].val+a[root<<1|1].val;
}
void pushdown(int root,int l,int r)
{
 if(a[root].tag)
 {
  int mid=(l+r)>>1;
  a[root].tag^=1;
  a[root<<1].tag^=1;
  a[root<<1|1].tag^=1;
  a[root<<1].val=(mid-l+1)-a[root<<1].val;
  a[root<<1|1].val=(r-mid)-a[root<<1|1].val;
  pushup(root);
 }
}
void update(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  a[root].val=(cr-cl+1)-a[root].val;
  a[root].tag^=1;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r);
 update(root<<1|1,mid+1,cr,l,r);
 pushup(root);
}
int query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return a[root].val;
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
int main()
{
 scanf("%d%d",&n,&m);
 while(m--)
 {
  int p,l,r;
  scanf("%d%d%d",&p,&l,&r);
  if(!p)update(1,1,n,l,r);
  else printf("%d\n",query(1,1,n,l,r));
 }
 return 0;
}