#include <stdio.h>
#include <string.h>
int n,l,s,ai,bi,ti,map[1001][1001],ans[1001],anss=0;
int main()
{
 memset(map,0x3f,sizeof(map));
 scanf("%d%d%d",&n,&l,&s);
 for(int i=1;i<=l;i++)
 {
  scanf("%d %d %d",&ai,&bi,&ti);
  map[ai][bi]=ti;
 }
 for(int i=1;i<=n;i++)
 { 
  for(int j=1;j<=n;j++)
  {
   if(j==i)continue;
   for(int z=1;z<=n;z++)
   {
    if(z==i||z==j)continue;
    else if(map[j][i]+map[i][z]<map[j][z])map[j][z]=map[j][i]+map[i][z];
   }
  }
 }
 for(int i=1;i<=n;i++)
 {
  if(i==s)continue;
  ans[i]=map[i][s]+map[s][i];
  if(ans[i]>anss)anss=ans[i];
 }
 printf("%d",anss);
 return 0;
}
