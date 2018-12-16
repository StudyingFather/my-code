#include <cstdio>
#include <algorithm>
using namespace std;
int a[5005],b[5005];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 for(int i=1;i<=n;i++)
 {
  bool flag=false;
  for(int j=1;j<=ans;j++)
   if(b[j]<=a[i])
   {
   	b[j]++;
   	flag=true;
   	break;
   }
  if(!flag)b[++ans]=1;
 }
 printf("%d\n",ans);
 return 0;
}
