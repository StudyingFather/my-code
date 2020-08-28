/*
 Name: Kick Start 2019 Round A Problem A
 Author: StudyingFather
 Date: 2019/06/13 20:25
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#define INF 2147483647
using namespace std;
int a[100005];
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  int n,p;
  scanf("%d%d",&n,&p);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  int sum=0,ans=INF;
  for(int i=1;i<=n;i++)
  {
   sum+=a[i];
   if(i>=p)
   {
    ans=min(ans,a[i]*p-sum);
    sum-=a[i-p+1];
   }
  }
  printf("Case #%d: %d\n",kase,ans);
 }
 return 0;
}