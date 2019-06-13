#include <cstdio>
int main()
{
 int n,sum=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  if(x==0)
  {
   if(sum%2)
   {
    puts("NO");
    return 0;
   }
   sum=0;
  }
  else sum+=x;
 }
 if(sum%2)puts("NO");
 else puts("YES");
 return 0;
}