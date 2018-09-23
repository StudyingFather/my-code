#include <cstdio>
#include <algorithm>
using namespace std; 
int ans=0;
bool is_hw(int num)
{
 int num1=num,num2=0;
 while(num1!=0)
 {
  num2*=10;
  num2+=num1%10;
  num1/=10; 
 }
 return num2==num;
}
int main()
{
 for(int i=100;i<=999;i++)
  for(int j=i;j<=999;j++)
  {
   int num=i*j;
   if(is_hw(num))ans=max(ans,num);
  }
 printf("%d",ans);
 return 0;
}
