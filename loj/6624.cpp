/*
 Name: loj 6624
 Author: StudyingFather
 Date: 2019/08/12 20:12
 Website: https://studyingfather.com
*/
#include <cstdio>
int main()
{
 int y;
 scanf("%d",&y);
 printf("%d\n",14-((y-1911)+y/4-477)%7);
 return 0;
}