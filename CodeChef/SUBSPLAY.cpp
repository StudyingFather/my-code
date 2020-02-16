#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100005];
int t[35];
int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
  int n;
  scanf("%d",&n);
  scanf("%s",s+1);
  int ans=0;
  memset(t,0,sizeof(t));
  for(int i=1;i<=n;i++)
  {
   int c=s[i]-'a';
   if(t[c])
    ans=max(ans,n-(i-t[c]));
   t[c]=i;
  }
  printf("%d\n",ans);
 }
 return 0;
}