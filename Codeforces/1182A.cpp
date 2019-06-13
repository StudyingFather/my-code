#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n;
 scanf("%d",&n);
 if(n%2)puts("0");
 else
 {
  n/=2;
  int ans=1;
  for(int i=1;i<=n;i++)
   ans*=2;
  printf("%d\n",ans);
 }
 return 0;
}