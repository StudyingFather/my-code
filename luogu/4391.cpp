#include <cstdio>
#include <algorithm>
using namespace std;
char s[1000005];
int nxt[1000005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s+1);
 for(int i=2,j=0;i<=n;i++)
 {
  while(j&&s[i]!=s[j+1])
   j=nxt[j];
  if(s[i]==s[j+1])j++;
  nxt[i]=j;
 }
 printf("%d\n",n-nxt[n]);
 return 0;
}