#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[105];
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int res=0;
 for(int i=1;i<=n;i++)
 {
  int ok=0;
  for(int j=1;j<=n&&!ok;j++)
  {
   for(int k=j+1;k<=n&&!ok;k++)
    if(a[j]+a[k]==a[i])ok=1;
   res+=ok;
  }
 }
 printf("%d\n",res);
 return 0;
}
