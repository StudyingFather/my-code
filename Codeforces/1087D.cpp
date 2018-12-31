#include <cstdio>
int a[200005];
int main()
{
 int n,s,cnt=0;
 scanf("%d%d",&n,&s);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d %d",&u,&v);
  a[u]++,a[v]++;
 }
 for(int i=1;i<=n;i++)
  if(a[i]==1)cnt++;
 printf("%.10lf\n",s*2.0/cnt);
 return 0;
}
