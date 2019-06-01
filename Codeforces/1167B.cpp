#include <cstdio>
#include <algorithm>
int a[15]={0,4,8,15,16,23,42},b[15];
using namespace std;
int main()
{
 for(int i=1;i<=4;i++)
 {
  printf("? %d %d\n",i,i+1);
  fflush(stdout);
  scanf("%d",&b[i]);
 }
 while(1)
 {
  int flag=1;
  for(int i=1;i<=4;i++)
   if(a[i]*a[i+1]!=b[i])
   {
    next_permutation(a+1,a+7);
    flag=0;
    break;
   }
  if(!flag)continue;
  printf("! ");
  for(int i=1;i<=6;i++)
   printf("%d ",a[i]);
  fflush(stdout);
  return 0;
 }
}