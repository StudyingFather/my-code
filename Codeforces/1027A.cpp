#include <cstdio>
#include <algorithm>
using namespace std;
char s1[105];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int len;
  scanf("%d",&len);
  scanf("%s",s1);
  int flag=1;
  for(int i=0;i<len/2;i++)
   if(s1[i]!=s1[len-i-1]&&abs(s1[i]-s1[len-i-1])!=2)
   {
    flag=0;
    break;
   }
  if(flag)puts("YES");
  else puts("NO");
 }
 return 0;
}
