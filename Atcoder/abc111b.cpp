#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[5],maxc;
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 maxc=s[0];
 for(int i=0;i<len;i++)
  if(s[i]>s[0])
  {
   maxc=s[0]+1;
   break;
  }
 for(int i=0;i<len;i++)
  printf("%c",maxc);
 return 0;
}