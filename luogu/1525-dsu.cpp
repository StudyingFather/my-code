#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int a,b,c;
}a[200005];
int fa[50005];
bool cmp(const node&a,const node&b)
{
 return a.c>b.c;
}
int find(int a)
{
 return fa[a]==a?a:fa[a]=find(fa[a]);
}
void unionn(int x,int y)
{
 x=find(x);
 y=find(y);
 fa[y]=x;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=2*n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
 sort(a+1,a+m+1,cmp);
 for(int i=1;i<=m;i++)
 {
  if(find(a[i].a)==find(a[i].b))
  {
   printf("%d",a[i].c);
   return 0;
  }
  unionn(a[i].a,a[i].b+n);
  unionn(a[i].b,a[i].a+n);
 }
 printf("0");
 return 0;
}
