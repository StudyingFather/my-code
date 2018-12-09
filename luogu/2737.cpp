#include <cstdio>
#include <algorithm>
#define MAXANS 65025
using namespace std;
int a[15],f[70005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 f[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=MAXANS;j++)
   if(j-a[i]>=0&&f[j-a[i]])f[j]=1;
 for(int i=MAXANS;i>0;i--)
  if(!f[i])
  {
   if(i<=MAXANS-1)printf("%d\n",i);
   else break;
   return 0;
  }
 puts("0");
 return 0;
}
