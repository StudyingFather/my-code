#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[15];
int main()
{
 int ans=1000;
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  s[i]-='0';
 for(int i=2;i<len;i++)
 {
  int num=s[i-2]*100+s[i-1]*10+s[i];
  ans=min(ans,abs(num-753));
 }
 printf("%d\n",ans);
 return 0;
}
