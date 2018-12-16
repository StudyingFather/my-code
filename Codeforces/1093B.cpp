#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1005];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  bool flag=true;
  scanf("%s",s);
  int len=strlen(s);
  sort(s,s+len);
  for(int i=0;i<len/2;i++)
   if(s[i]!=s[len-i-1])
   {
   	flag=false;
   	break;
   }
  if(flag)puts("-1");
  else puts(s);
 }
 return 0;
}
