/*
 Name: Atcoder Beginner Contest 141A
 Author: StudyingFather
 Date: 2019/08/18 20:03
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
char s[15];
int main()
{
 scanf("%s",s);
 if(!strcmp(s,"Sunny"))puts("Cloudy");
 else if(!strcmp(s,"Cloudy"))puts("Rainy");
 else puts("Sunny");
 return 0;
}