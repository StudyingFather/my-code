#include <cstdio>
#include <algorithm>
using namespace std;
int a[5];
int main()
{
 scanf("%d%d%d",&a[1],&a[2],&a[3]);
 sort(a+1,a+4);
 printf("%d\n",a[1]+a[2]);
 return 0;
}