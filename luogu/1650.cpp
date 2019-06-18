#include <cstdio>
#include <algorithm> 
#include <cstring>
using namespace std; 
int a[100005],b[100005],n;
bool cmp(int a,int b)
{
 return a>b;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++) 
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 sort(a+1,a+n+1,cmp);
 sort(b+1,b+n+1,cmp);
 int ans=0;
 int ii=n,jj=n,i=1,j=1;
 while(i<=ii)
  if(a[i]>b[j])
  {
   ans+=200;
   i++;
   j++;
  }
  else if(a[i]<b[j])
  {
   ans-=200;
   j++;
   ii--;
  }
  else
  {
   if(a[ii]>b[jj])
   {
    ans+=200;
    ii--;
    jj--;
   }
   else
   {
    if(a[ii]<b[j])ans-=200;
    ii--;
    j++;
   }
  }
 printf("%d",ans);
 return 0;
}