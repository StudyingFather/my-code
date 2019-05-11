#include <cstdio>
#include <algorithm>
using namespace std;
double seg1[400005],seg2[400005],add[400005],a[100005];
void pushup(int x)
{
 seg1[x]=seg1[x<<1]+seg1[x<<1|1];
 seg2[x]=seg2[x<<1]+seg2[x<<1|1];
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  seg1[root]=a[l];
  seg2[root]=a[l]*a[l];
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
 return;
}
void pushdown(int root,int cl,int cr)
{
 int mid=(cl+cr)>>1;
 seg2[root<<1]+=2*add[root]*seg1[root<<1]+(mid-cl+1)*add[root]*add[root];
 seg2[root<<1|1]+=2*add[root]*seg1[root<<1|1]+(cr-mid)*add[root]*add[root];
 seg1[root<<1]+=add[root]*(mid-cl+1);
 seg1[root<<1|1]+=add[root]*(cr-mid);
 add[root<<1]+=add[root];
 add[root<<1|1]+=add[root];
 add[root]=0;
}
void update(int root,int cl,int cr,int l,int r,double x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  add[root]+=x;
  seg2[root]+=2*x*seg1[root]+(cr-cl+1)*x*x;
  seg1[root]+=(cr-cl+1)*x;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
 return;
}
double query1(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return seg1[root];
 else
 {
  pushdown(root,cl,cr);
  int mid=(cl+cr)>>1;
  return query1(root<<1,cl,mid,l,r)+query1(root<<1|1,mid+1,cr,l,r);
 }
}
double query2(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return seg2[root];
 else
 {
  pushdown(root,cl,cr);
  int mid=(cl+cr)>>1;
  return query2(root<<1,cl,mid,l,r)+query2(root<<1|1,mid+1,cr,l,r);
 }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%lf",&a[i]);
 build(1,1,n);
 for(int i=1;i<=m;i++)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int x,y;
   double k;
   scanf("%d%d%lf",&x,&y,&k);
   update(1,1,n,x,y,k);
  }
  else if(op==2)
  {
   int x,y;
   scanf("%d%d",&x,&y);
   printf("%.4lf\n",query1(1,1,n,x,y)/(y-x+1));
  }
  else
  {
   int x,y;
   scanf("%d%d",&x,&y);
   double res1=query1(1,1,n,x,y)/(y-x+1),res2=query2(1,1,n,x,y)/(y-x+1);
   printf("%.4lf\n",res2-res1*res1);
  }
 }
 return 0;
}