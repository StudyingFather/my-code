#include <stdio.h>
#include <algorithm>
using namespace std;
int n,a[1005];
int main()
{
 scanf("%d",&n);
 for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
 sort(a+0,a+n);
 for(int i=0;i<n;i++)
  printf("%d ",a[i]);
 return 0;
}
