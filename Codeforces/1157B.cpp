#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[200005];
int f[15];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 for(int i=1;i<=9;i++)
  scanf("%d",&f[i]);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  s[i]-='0';
 int flag=0;
 for(int i=0;i<len;i++)
  if(s[i]>f[s[i]]&&flag)break;
  else if(s[i]<f[s[i]])
  {
   flag=1;
   s[i]=f[s[i]];
  }
 for(int i=0;i<len;i++)
  printf("%d",s[i]);
 return 0;
}