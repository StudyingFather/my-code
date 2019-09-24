/*
 Name: Codeforces 1230B
 Author: StudyingFather
 Date: 2019/09/23 22:17
 Website: https://studyingfather.com
*/
#include <cstdio>
char s[200005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 scanf("%s",s);
 if(n==1)
 {
  if(k)puts("0");
  else puts(s);
 }
 else
 {
  if(s[0]!='1'&&k)s[0]='1',k--;
  for(int i=1;i<n&&k;i++)
   if(s[i]!='0')s[i]='0',k--;
  puts(s);
 }
 return 0;
}