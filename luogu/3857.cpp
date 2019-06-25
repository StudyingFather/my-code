#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 2008
using namespace std;
char s[55];
long long p[55];
int main()
{
 int n,m,cnt=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  scanf("%s",s+1);
  long long len=strlen(s+1),x=0;
  for(int i=1;i<=len;i++)
   if(s[i]=='O')x+=(1ll<<i);
  for(int i=50;i>=0;i--)
   if((x>>i)&&1)
   {
    if(p[i])x^=p[i];
    else
    {
     cnt++;
     p[i]=x;
     break;
    }
   }
 }
 printf("%d\n",int((1ll<<cnt)%MOD));
 return 0;
}