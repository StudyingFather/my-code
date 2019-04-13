#include <cstdio>
#include <cstring>
char s[300005];
int main()
{
 int n,cnt1=0,cnt2=0;
 scanf("%d",&n);
 scanf("%s",s);
 if(n%2)
 {
  puts(":(");
  return 0;
 }
 for(int i=0;i<n;i++)
  if(s[i]=='(')cnt1++;
  else if(s[i]==')')cnt2++;
 if(cnt1>n/2||cnt2>n/2)
 {
  puts(":(");
  return 0;
 }
 for(int i=0;i<n;i++)
  if(s[i]=='?')
  {
   if(cnt1<n/2)s[i]='(',cnt1++;
   else s[i]=')',cnt2++;
  }
 cnt1=cnt2=0;
 for(int i=0;i<n;i++)
 {
  if(s[i]=='(')cnt1++;
  else if(s[i]==')')cnt2++;
  if(cnt1==cnt2&&i!=n-1)
  {
   puts(":(");
   return 0;
  }
  if(cnt1<cnt2)
  {
   puts(":(");
   return 0;
  }
 }
 puts(s);
 return 0;
}