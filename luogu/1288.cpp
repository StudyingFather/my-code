#include <cstdio>
int a[25];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  if(!a[i])
  {
   if(i%2==0)
   {
    puts("YES");
    return 0;
   }
   else break;
  }
 for(int i=n;i>=1;i--)
  if(!a[i])
  {
   if((n-i+1)%2==0)
   {
    puts("YES");
    return 0;
   }
   else break;
  }
 puts("NO");
 return 0;
}