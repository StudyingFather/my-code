/*
 Name: Google Code Jam 2019 Qualification Round Problem B
 Author: StudyingFather
 Date: 2019/06/13 21:18
 Website: https://studyingfather.com
*/
#include <cstdio>
char s[100005];
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  int n;
  scanf("%d",&n);
  scanf("%s",s);
  printf("Case #%d: ",kase);
  for(int i=0;i<2*n-2;i++)
   if(s[i]=='E')putchar('S');
   else putchar('E');
  puts("");
 }
 return 0;
}