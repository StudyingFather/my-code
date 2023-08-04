/*
 Name: Atcoder Beginner Contest 141B
 Author: StudyingFather
 Date: 2019/08/18 20:07
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
char s[105];
int main()
{
 scanf("%s",s+1);
 int len=strlen(s+1),flag=true;
 for(int i=1;i<=len;i++)
  if(i%2)
  {
   if(s[i]=='L')flag=false;
  }
  else
  {
   if(s[i]=='R')flag=false;
  }
 puts(flag?"Yes":"No");
 return 0;
}
