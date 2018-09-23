#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int w,h;
  scanf("%d%d",&w,&h);
  if(i==1)a[i]=max(w,h);
  else
  {
   if(a[i-1]<w&&a[i-1]<h)
   {
   	printf("NO");
   	return 0;
   }
   else if(a[i-1]<w)a[i]=h;
   else if(a[i-1]<h)a[i]=w;
   else a[i]=max(w,h);
  }
 }
 printf("YES");
 return 0;
}
