#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char str[105];
int main()
{
 int ans=0;
 char arr='a';
 scanf("%s",str);
 int len=strlen(str);
 for(int i=0;i<len;i++)
 {
  ans+=min(abs(arr-str[i]),26-abs(arr-str[i]));
  arr=str[i];	
 }
 printf("%d",ans);
 return 0;
}
