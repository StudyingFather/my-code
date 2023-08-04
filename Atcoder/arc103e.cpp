#include <cstdio>
#include <cstring>
char s[100005];
int p[100005];
bool check()
{
 int n=strlen(s+1);
 for(int i=1;i<n;i++)
  if(s[i]!=s[n-i])return false;
 return true;
}
int main()
{
 scanf("%s",s+1);
 int n=strlen(s+1);
 if(s[1]!='1'||s[n]!='0'||!check())
 {
  puts("-1");
  return 0;
 }
 int tot=0;
 for(int i=1;i<=n;i++)
  if(s[i]=='1')p[++tot]=i;
 for(int i=1;i<=tot;i++)
  printf("%d %d\n",i,i+1);
 int cnt=tot+1;
 for(int i=1;i<=tot;i++)
 {
  int d=p[i]-p[i-1]-1;
  while(d--)
   printf("%d %d\n",i,++cnt);
 }
 return 0;
}