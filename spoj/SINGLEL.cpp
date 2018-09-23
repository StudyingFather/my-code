#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int pow_2(int a)
{
 int ans=1;
 for(int i=1;i<=a;i++)
  ans*=2;
 return ans; 
}
int s[305],p[305];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=64;i++)
 {
  int t=0;
  memset(s,0,sizeof(s));
  for(int i=0;i<=pow_2(n)-1;i++)
   p[i]=i;
  while(t!=-1)
  {
   for(int i=0;i<=pow_2(n)-1;i++)
    printf("%d",s[i]);
   puts("");
   fflush(stdout);
   scanf("%d",&t);
   if(t==-1)break;
   else
   {
    s[t]=!s[t];
    for(int i=0;i<t;i++)
     s[i]=0;
   }
  }
 }
 return 0;
}
