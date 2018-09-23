#include <stdio.h>
int n,a[15],ans,b[10005][15];
void dfs(int d)
{
 if(d==11)
 {
  int tot=0;
  for(int i=1;i<=10;i++)
   tot+=a[i];
  if(tot==n)
  {
   ans++;
   for(int i=1;i<=10;i++)
    b[ans][i]=a[i];
  }
  return;
 }
 for(int i=1;i<=3;i++)
 {
  a[d]=i;
  dfs(d+1);
  a[d]=0;
 }
}
int main()
{
 scanf("%d",&n);
 if(n>30)printf("0");
 else
 {
  dfs(1);
  printf("%d\n",ans);
  for(int i=1;i<=ans;i++)
  {
   for(int j=1;j<=10;j++)
    printf("%d ",b[i][j]);
   puts("");
  }
 }
 return 0;
}
