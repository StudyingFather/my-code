#include <cstdio>
#include <algorithm>
using namespace std;
int f(int a)
{
 int ans=1;
 for(int i=1;i<=a;i++)
  ans*=i;
 return ans;
}
int main()
{
 int a,b;
 scanf("%d%d",&a,&b);
 printf("%d",f(min(a,b)));
 return 0;
}
