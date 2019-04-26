#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[55];
int main()
{
 scanf("%s",s);
 int len=strlen(s),cnt=0;
 for(int i=0;i<len;i++)
  if(s[i]=='a')cnt++;
 printf("%d\n",min(len,2*cnt-1));
 return 0;
}