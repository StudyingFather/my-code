#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  num=abs(num);
  ans=gcd(num,ans);
 }
 printf("%d\n",ans);
 return 0;
}
