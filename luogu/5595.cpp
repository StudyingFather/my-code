/*
 Name: luogu P5595
 Author: StudyingFather
 Date: 2019/10/20 14:17
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
char s[1000005],s1[1000005],s2[1000005];
int main()
{
 scanf("%s",s);
 int len=strlen(s);
 bool flag=true;
 for(int i=len-1;i>=0;i--)
 {
  if(s[i]!='Z')flag=false;
  if(s[i]=='Z'&&!flag)
  {
   puts("-1");
   return 0;
  }
  if(s[i]=='Z')s1[i]=s2[i]='0';
  else if(s[i]=='X')s1[i]='9',s2[i]='0';
  else s1[i]='0',s2[i]='9';
 }
 puts(s1);
 puts(s2);
 return 0;
}