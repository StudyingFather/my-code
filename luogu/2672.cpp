#include <stdio.h>
int n,maxn,sum,a[100001],b[100001],c[100001][101],t,p=0,x,y;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&t);
  b[t]++;
  c[t][b[t]]=i; 
 }
 for(int i=1;i<=n;i++)
 {
  maxn=0;x=0;y=0;
  for(int j=0;j<=999;j++)
   if(b[j]>0)
    if(a[c[j][b[j]]]>p&&(a[c[j][b[j]]]-p)*2+j>maxn)
    {
     maxn=(a[c[j][b[j]]]-p)*2+j;
     x=j;  
     y=a[c[j][b[j]]]; 
    }
    else if(a[c[j][b[j]]]<=p&&j>maxn)
    {
     maxn=x=j;  
     y=p;
    }
    p=y;
    b[x]--;
    sum+=maxn;
    printf("%d\n",sum);
 }
 return 0;
}
