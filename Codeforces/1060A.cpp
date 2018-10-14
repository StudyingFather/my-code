#include <cstdio>
#include <algorithm>
using namespace std;
char s[105];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 scanf("%s",s);
 for(int i=0;i<n;i++)
  if(s[i]=='8')ans++;
 printf("%d",min(ans,n/11));
 return 0;
}