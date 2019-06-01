#include <cstdio>
int n,res[15],visr[15],visx1[35],visx2[35],tot;
void dfs(int d)
{
 if(d>n)
 {
  if(tot<3)
  {
   for(int i=1;i<=n;i++)
    printf("%d ",res[i]);
   puts("");
  }
  tot++;
 }
 else
  for(int i=1;i<=n;i++)
  {
   if((!visr[i])&&(!visx1[d+i])&&(!visx2[d-i+n]))
   {
    res[d]=i;
    visr[i]=visx1[d+i]=visx2[d-i+n]=1;
    dfs(d+1);
    res[d]=0;
    visr[i]=visx1[d+i]=visx2[d-i+n]=0;
   }
  }
}
int main()
{
 scanf("%d",&n);
 dfs(1);
 printf("%d\n",tot);
 return 0;
}