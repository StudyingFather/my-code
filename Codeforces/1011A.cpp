#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[55];
int main()
{
 int n,k,ans=0,cnt=1;
 char c;
 scanf("%d%d",&n,&k);
 scanf("%s",s);
 sort(s,s+n);
 c=s[0];
 ans+=c-'a'+1;
 for(int i=1;i<n;i++)
 {
  if(cnt==k)break;
  if(s[i]-c>=2)c=s[i],ans+=c-'a'+1,cnt++;
 }
 if(cnt==k)printf("%d",ans);
 else printf("-1");
 return 0;
}
