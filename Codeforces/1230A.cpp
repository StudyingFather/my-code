/*
 Name: Codeforces 1230A
 Author: StudyingFather
 Date: 2019/09/23 22:08
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5];
int main()
{
 for(int i=1;i<=4;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+5);
 if(a[4]==a[1]+a[2]+a[3]||a[4]+a[1]==a[2]+a[3])puts("YES");
 else puts("NO");
 return 0;
}