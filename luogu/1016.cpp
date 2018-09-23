#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
double d1,c,d2,p;
double value[10000],way[10000],over[10000],x[10000];
int i,j,n;
int main()
{
 scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n); 
 for(int i=1;i<=n;i++)
  scanf("%lf%lf",&way[i],&value[i]);
 n++;
 way[n]=d1;
 value[0]=p;
 int l=c*d2;
 while(i<n)
 {
  j=i+1;
  if(way[j]-way[i]>l)
  {
   printf("No Solution");
   return 0;
  }
  while(way[j]-way[i]<=l)
  { 
   if(value[j]<value[i])break;
   j++;
  }
  if(way[j]-way[i]<=l)
  { 
   if(over[i]*d2>=way[j]-way[i]) 
    over[j]=over[i]-(way[j]-way[i])/d2;
   else x[i]=(way[j]-way[i])/d2-over[i]; 
  }
  else
  { 
   x[i]=c-over[i];
   j=i+1;
   over[j]=c-(way[j]-way[i])/d2;
  }
  i=j;
 }
 double ans=0;
 for(int i=0;i<=n-1;i++)
  ans+=x[i]*value[i];
 printf("%.2f\n",ans);
 return 0;
}
