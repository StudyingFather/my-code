#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
 int l,r,ans;
}que[10010];
int a[20010],fa[40010],n,m,t;
void init()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  char s[5];
  scanf("%d%d%s",&que[i].l,&que[i].r,s);
  que[i].ans=(s[0]=='o'?1:0);
  a[++t]=que[i].l-1;
  a[++t]=que[i].r;
 }
 sort(a+1,a+t+1);
 n=unique(a+1,a+t+1)-a-1;
}
int find(int x)
{
 if(x==fa[x])return x;
 return fa[x]=find(fa[x]);
}
void setfa()
{
 for(int i=1;i<=10000;i++)
  fa[i]=i;
}
int main()
{
 init();
 setfa();
 for(int i=1;i<=m;i++)
 {
  int x=lower_bound(a+1,a+n+1,que[i].l-1)-a;
  int y=lower_bound(a+1,a+n+1,que[i].r)-a;
  int x_odd=x,x_even=x+n;
  int y_odd=y,y_even=y+n;
  if(que[i].ans==0)
  {
   if(find(x_odd)==find(y_even))
   {
    printf("%d",i-1);
    return 0;
   }
   fa[find(x_odd)]=find(y_odd);
   fa[find(x_even)]=find(y_even);
  }
  else
  {
   if(find(x_odd)==find(y_odd))
   {
    printf("%d",i-1);
    return 0;
   }
   fa[find(x_odd)]=find(y_even);
   fa[find(x_even)]=find(y_odd);
  }
 }
 printf("%d",m);
 return 0;
}
