#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[705];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 scanf("%s",s+1);
 for(int i=n+1;i<=2*n;i++)
  s[i]=s[i-n];
 for(int i=1;i<=2*n;i++)
 {
  int l=i,r=i+1,res=0;
  char lc=s[l],rc=s[r];
  while(l>0&&lc=='w')
   lc=s[--l],res++;
  while(r<=2*n&&lc=='w')
   rc=s[++r],res++;
  while(l>0&&(s[l]==lc||s[l]=='w'))
   res++,l--;
  while(r<=2*n&&(s[r]==rc||s[r]=='w'))
   res++,r++;
  ans=max(ans,res);
 }
 printf("%d\n",min(ans,n));
 return 0;
}
