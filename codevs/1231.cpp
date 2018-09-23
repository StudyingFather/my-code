#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int a,b,c;
}a[100005];
int fa[100005];
int cmp(const node&a,const node&b)
{
 return a.c<b.c;
}
int find(int m)
{
 return m==fa[m]?fa[m]:fa[m]=find(fa[m]);
}
void my_union(int m,int n)
{
 m=find(m);
 n=find(n);
 fa[m]=n;
}
void start(int n)
{
 for(int i=1;i<=n;i++)
  fa[i]=i;
}
int main()
{
 int n,m;
 long long ans=0;
 scanf("%d%d",&n,&m);
 start(n);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
 sort(a+1,a+m+1,cmp);
 int num=0,e=1;
 while(num<n-1)
  if(find(a[e].a)!=find(a[e].b))
  {
   my_union(a[e].a,a[e].b);
   ans+=a[e].c;
   num++;
  }
  else e++;
 printf("%lld",ans);
 return 0;
}
