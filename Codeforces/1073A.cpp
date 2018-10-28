#include <cstdio>
#include <algorithm>
using namespace std;
char a[1005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",a);
 for(int i=0;i<n-1;i++)
  if(a[i]!=a[i+1])
  {
   puts("YES");
   printf("%c%c",a[i],a[i+1]);
   return 0;
  }
 puts("NO");
 return 0;
}
