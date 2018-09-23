#include <cstdio>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
 return a>b;
}
int a[30005];
int main()
{
 int w,n,ans=0;
 scanf("%d%d",&w,&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1,cmp);
 int l=1,r=n;
 while(l<=r)
 {
  if(a[l]+a[r]<=w)
  {
   l++;
   r--;
   ans++;
  }
  else
  {
   l++;
   ans++;
  }
 }
 printf("%d",ans);
 return 0;
}
