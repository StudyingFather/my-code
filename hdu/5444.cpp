#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct tree
{
 int l,r,val;
}tr[1010];
int tot=1,root,n;
void insert(int p,int val)
{
 if(tr[p].val<val&&tr[p].r)insert(tr[p].r,val);
 else if(tr[p].val>val&&tr[p].l)insert(tr[p].l,val);
 else
 {
  tr[tot].l=tr[tot].r=0;
  tr[tot].val=val;
  if(tr[p].val>val)tr[p].l=tot;
  else tr[p].r=tot;
  tot++;
  return;
 }
 return;
}
void query(int p,int val)
{
 if(val==tr[p].val)
 {
  printf("\n");
  return; 
 }
 if(val<tr[p].val)
 {
  printf("E");
  query(tr[p].l,val);
 }
 else
 {
  printf("W");
  query(tr[p].r,val);
 }
}
int main()
{
 int t;
 int n,a,q,val;
 scanf("%d",&t);
 while(t--)
 {
  tot=1;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&a);
   if(i==1)
   {
    tr[tot].l=tr[tot].r=0;
    tr[tot].val=a;
    tot++;
   }
   else insert(1,a);
  }
  scanf("%d",&q);
  while(q--)
  {
   scanf("%d",&val);
   query(1,val);
  }
 }
 return 0;
}
