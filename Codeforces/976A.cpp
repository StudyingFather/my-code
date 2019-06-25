#include <cstdio>
int n;
char s[105];
int main()
{
 scanf("%d",&n);
 scanf("%s",s);
 int n0=0;
 for(int i=0;i<n;i++)
  if(s[i]=='0')n0++;
 if(n0!=n)printf("1");
 for(int i=1;i<=n0;i++)
  printf("0");
 return 0;
}
