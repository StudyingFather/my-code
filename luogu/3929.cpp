#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],n;
bool calc(int x)
{
 int cnt=0;
 for(int i=2;i<=n;i++,x=!x)
  if(a[i]!=a[i-1]&&(a[i]>a[i-1])!=x)
  {
   cnt++;
   if(cnt>1)return false;
   x=!x;
   i++;
  }
 return true;
}
int main()
{
 while(~scanf("%d",&n))
 {
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  if(calc(0)||calc(1))puts("Yes");
  else puts("No");
 }
 return 0;
}