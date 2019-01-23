#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[200005];
int t[35];
int main()
{
 int n,k,ans=0;
 scanf("%d%d",&n,&k);
 scanf("%s",s);
 int len=strlen(s),cnt=0,cur=s[0];
 for(int i=0;i<len;i++)
 {
  if(cur==s[i])cnt++;
  else
  {
   t[cur-'a'+1]+=cnt/k;
   cur=s[i];
   cnt=1;
  }
 }
 t[cur-'a'+1]+=cnt/k;
 for(int i=1;i<=26;i++)
  ans=max(ans,t[i]);
 printf("%d\n",ans);
 return 0;
}