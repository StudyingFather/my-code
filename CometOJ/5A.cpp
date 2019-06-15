#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[200005];
int t[15];
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  t[s[i]-'0']++;
 printf("%d\n",min(t[1]/3,min(t[4]/2,t[5])));
 return 0;
}