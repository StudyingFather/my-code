/*
 Name: luogu P3424
 Author: StudyingFather
 Date: 2019/09/27 15:21
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[1000005],b[1000005],ans[1000005];
void dec(int x)
{
 ans[x]-=2;
 if(x==1)ans[2]++;
 else if(x==2)ans[1]++,ans[3]++;
 else ans[x-2]++,ans[x+1]++;
}
void add(int x)
{
 while(ans[x]&&ans[x+1])
 {
  ans[x]--,ans[x+1]--,ans[x+2]++;
  x+=2;
 }
}
int main()
{
 int x,y;
 scanf("%d",&x);
 for(int i=1;i<=x;i++)
  scanf("%d",&a[i]);
 scanf("%d",&y);
 for(int i=1;i<=y;i++)
  scanf("%d",&b[i]);
 int len=max(x,y);
 for(int i=1;i<=len;i++)
  ans[i]=a[i]+b[i];
 for(int i=len;i;i--)
 {
  if(ans[i]>1)dec(i);
  add(i);
  if(ans[i+1]>1)dec(i+1);
  add(i+1);
  if(ans[i+2]>1)dec(i+2);
  add(i+2);
 }
 if(ans[len+1])len++;
 if(ans[len+2])len+=2;
 printf("%d ",len);
 for(int i=1;i<=len;i++)
  printf("%d ",ans[i]);
 return 0;
}