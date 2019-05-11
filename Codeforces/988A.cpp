#include <cstdio>
int t[105],res[105];
int main()
{
 int n,k,cnt=0;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  if(!t[x])
  {
   res[++cnt]=i;
   t[x]++;
  }
 }
 if(cnt<k)puts("NO");
 else
 {
  puts("YES");
  for(int i=1;i<=k;i++)
   printf("%d ",res[i]);
 }
 return 0;
}