#include <cstdio>
#include <algorithm>
using namespace std;
int maxt,vis[80005],ans,tot;
int main()
{
 int a,b;
 scanf("%d%d",&a,&b);
 if(a==0&&b==0)
 {
  printf("0\n\n0\n\n");
  return 0;
 } 
 for(int i=1;;i++)
 {
  tot+=i;
  if(tot>a+b)
  {
   maxt=i-1; 
   break;
  }
 }
 tot=0;
 for(int i=maxt;i>=1;i--)
 {
  if(i+tot>=a)
  {
   if(a==0)
   {
   	printf("0\n");
   	ans=maxt;
   	break;
   }
   printf("%d\n",min(a-tot,maxt)?maxt-i+1:maxt-i);
   for(int j=i+1;j<=maxt;j++)
    printf("%d ",j),vis[j]=1;
   if(min(a-tot,maxt))printf("%d\n",min(a-tot,maxt));
   else puts("");
   vis[min(a-tot,maxt)]=1;
   ans=min(a-tot,maxt)?i-1:i;
   break;
  }
  tot+=i;
  if(i==1)
  {
   printf("%d\n",maxt);
   for(int i=1;i<=maxt;i++)
    printf("%d ",i);
   puts("");
  }
 }
 printf("%d\n",ans);
 if(ans==0)return 0;
 for(int i=1;i<=maxt;i++)
  if(!vis[i])printf("%d ",i);
 return 0;
}
