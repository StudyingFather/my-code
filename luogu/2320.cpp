#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
 int m,cnt=0;
 scanf("%d",&m);
 printf("%d\n",(int)log2(m)+1);
 while(m>0)
 {
  if(m%2)a[++cnt]=m/2+1;
  else a[++cnt]=m/2;
  m/=2;
 }
 sort(a+1,a+cnt+1);
 for(int i=1;i<=cnt;i++)
  printf("%d ",a[i]);
 return 0;
}
