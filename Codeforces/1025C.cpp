#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[200005];
int main()
{
 int res=1,ans=1;
 scanf("%s",s);
 int len=strlen(s);
 for(int i=0;i<len;i++)
  s[i+len]=s[i];
 for(int i=1;i<2*len-1;i++)
  if(s[i]!=s[i-1])
  {
   ans++;
   res=max(ans,res);
  }
  else ans=1;
 printf("%d",min(res,len));
 return 0;
}
