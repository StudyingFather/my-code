#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct query
{
 int l,r,bl,br,id;
}q[200005];
int a[200005],b[200005],t[200005],p[200005],ans[200005],res;
bool cmp(const query&a,const query&b)
{
 return a.bl<b.bl||(a.bl==b.bl&&a.br<b.br);
}
void add(int x)
{
 int&tmp=t[x];
 p[tmp]--;
 tmp++;
 p[tmp]++;
 res=max(tmp,res);
}
void del(int x)
{
 int&tmp=t[x];
 if(p[tmp]==1&&tmp==res)res--;
 p[tmp]--;
 tmp--;
 p[tmp]++;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]),b[i]=a[i];
 sort(b+1,b+n+1);
 int num=unique(b+1,b+n+1)-b;
 for(int i=1;i<=n;i++)
  a[i]=lower_bound(b+1,b+num+1,a[i])-b;
 int siz=sqrt(n);
 for(int i=1;i<=m;i++)
 {
  scanf("%d%d",&q[i].l,&q[i].r);
  q[i].bl=(q[i].l-1)/siz;
  q[i].br=(q[i].r-1)/siz;
  q[i].id=i;
 }
 sort(q+1,q+m+1,cmp);
 int l=1,r=0;
 p[0]=num;
 for(int i=1;i<=m;i++)
 {
  int ql=q[i].l,qr=q[i].r;
  while(r<qr)
  {
   r++;
   add(a[r]);
  }
  while(r>qr)
  {
   del(a[r]);
   r--;
  }
  while(l<ql)
  {
   del(a[l]);
   l++;
  }
  while(l>ql)
  {
   l--;
   add(a[l]);
  }
  ans[q[i].id]=res;
 }
 for(int i=1;i<=m;i++)
  printf("-%d\n",ans[i]);
 return 0;
}