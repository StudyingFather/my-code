#include <stdio.h>
#include <string.h>
int bed[205],t;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,k,ans=1;
  memset(bed,0,sizeof(bed));
  scanf("%d%d",&n,&k);
  for(int i=1;i<=k;i++)
  {
   int num;
   scanf("%d",&num);
   bed[num]++;
  }
  while(k!=n)
  {
   for(int i=1;i<=n;i++)
   {
    if(bed[i]==2)bed[i]=1;
    if(bed[i]==1)
    {
     if(i!=1&&bed[i-1]==0)
     {
      bed[i-1]=1;
      k++;
     }
     if(i!=n&&bed[i+1]==0)
     {
      bed[i+1]=-1;
      k++;
     }
    }
    if(bed[i]==-1)bed[i]=2;
   }
   ans++;
  }
  printf("%d\n",ans);
 }
 return 0;
}
