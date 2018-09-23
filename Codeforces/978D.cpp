#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 2000000005
int n,b[100005],c[100005],maxc=-INF,minc=INF,avec;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&b[i]);
  if(i==1)continue;
  c[i]=b[i]-b[i-1];
  avec+=c[i];
  maxc=max(maxc,c[i]);
  minc=min(minc,c[i]);
 }
 avec=floor(avec*1.0/(n-1)+0.5);
 int ans=0;
 if(n==1||n==2)printf("0");
 else
 {
  if(maxc-minc>4)printf("-1");
  else
  {
   if(c[2]!=avec)
   {
   	ans++;
   	if(c[2]>avec)c[2]--;
   	else c[2]++;
   }
   for(int i=2;i<=n-1;i++)
   {
   	if(c[i+1]>avec)
   	{
   	 c[i+1]--;
   	 c[i]++;
   	 ans++;
   	}
   	else if(c[i+1]<avec)
   	{
   	 c[i+1]++;
   	 c[i]--;
   	 ans++;
   	}
   }
   if(c[n]!=avec)ans++;
   printf("%d",ans);
  }
 }
 return 0;
}
