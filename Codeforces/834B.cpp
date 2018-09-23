#include <cstdio>
#include <algorithm>
using namespace std;
struct door
{
 int o,c;
}a[30];
struct event
{
 int t,type;
}e[65];
int cmd(const event&a,const event&b)
{
 return a.t<b.t||(a.t==b.t&&a.type>b.type);
}
char s[1000005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
 {
  if(!a[s[i]-'A'+1].o)
   a[s[i]-'A'+1].o=i;
  a[s[i]-'A'+1].c=i;
 }
 int h=1;
 for(int i=1;i<=26;i++)
  if(a[i].o)
  {
   e[h++]={a[i].o,1};
   e[h++]={a[i].c,0};
  }
 sort(e+1,e+h,cmd);
 int ans=0;
 for(int i=1;i<h;i++)
 {
  if(e[i].type)
  {
   ans++;
   if(ans>k)
   {
    printf("YES");
    return 0;
   }
  }
  else ans--;
 }
 printf("NO");
 return 0;
}
