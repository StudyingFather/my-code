/*
 Name: Atcoder Beginner Contest 144B
 Author: StudyingFather
 Date: 2019/10/27 21:03
 Website: https://studyingfather.com
*/
#include <cstdio>
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=9;i++)
  if(n%i==0&&n/i<10)
  {
   puts("Yes");
   return 0;
  }
 puts("No");
 return 0;
}