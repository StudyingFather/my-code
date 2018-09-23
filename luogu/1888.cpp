#include <cstdio>
#include <algorithm>
using namespace std;
int a[3];
int gcd(int a,int b)
{
 return a%b==0?b:gcd(b,a%b);
}
int main()
{
 scanf("%d%d%d",&a[0],&a[1],&a[2]);
 sort(a,a+3);
 printf("%d/%d",a[0]/gcd(a[0],a[2]),a[2]/gcd(a[0],a[2]));
 return 0;
}
