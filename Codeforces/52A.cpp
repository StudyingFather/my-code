#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n,a1=0,a2=0,a3=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int a;
  scanf("%d",&a);
  if(a==1)a1++;
  if(a==2)a2++;
  if(a==3)a3++;
 }
 printf("%d",min(n-a1,min(n-a2,n-a3)));
 return 0;
}
