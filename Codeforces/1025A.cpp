#include <stdio.h>
int t[155];
char s[100005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 if(n==1)
 {
  puts("YES");
  return 0;
 }
 for(int i=0;i<n;i++)
 {
  t[(int)s[i]]++;
  if(t[(int)s[i]]>=2)
  {
   puts("YES");
   return 0;
  }
 }
 puts("NO");
 return 0;
}
