#include <cstdio>
#include <algorithm>
using namespace std;
int f[45];
int main()
{
 int n,sum=2;
 scanf("%d",&n);
 if(n==1)
 {
  puts("1");
  return 0;
 }
 f[1]=f[2]=1;
 for(int i=3;i<=n;i++)
  sum+=(f[i]=f[i-1]+f[i-2]);
 printf("%d\n",sum);
 return 0;
}