/*
 Name: luogu P5602
 Author: StudyingFather
 Date: 2019/10/27 15:51
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[300005];
bool cmp(int a,int b)
{
 return a>b;
}
int main()
{
 int n;
 scanf("%d",&n);
 double maxa=0;
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1,cmp);
 long long sum=0;
 for(int i=1;i<=n;i++)
 {
  sum+=a[i];
  if((double)sum*sum/i>maxa)maxa=(double)sum*sum/i;
  else break;
 }
 printf("%.8lf\n",maxa);
 return 0;
}