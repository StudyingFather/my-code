#include <stdio.h>
int a[10005],water[105];
int n,m,minw=10000,maxt,ans,arr;
void print()
{
 for(int i=1;i<=m;i++)
  printf("%d ",water[i]);
 puts("");
 printf("%d\n",ans);
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=m;i++)
 {
  water[i]=a[i];
  if(water[i]<minw&&water[i])minw=water[i];
  if(water[i]>maxt)maxt=water[i];
 }
 arr=m+1;
 while(1)
 {
  for(int i=1;i<=m;i++)
  {
   water[i]-=minw;
   if(water[i]<=0&&arr<=n)
   {
    water[i]=a[arr];
    arr++;
   }
   //print();
  }
  ans+=minw;
  minw=10000;
  maxt=0;
  for(int i=1;i<=m;i++)
  {
   if(water[i]<minw&&water[i]>0)minw=water[i];
   if(water[i]>maxt)maxt=water[i];
  }
  if(arr>n)
  {
   ans+=maxt;
   break;
  }  
 }
 printf("%d",ans);
 return 0;
}
