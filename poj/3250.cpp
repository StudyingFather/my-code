#include <iostream>
#include <algorithm>
using namespace std;
int a[80005],st[80005],t;
long long sum;
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  while(t&&st[t]<=a[i])//将所有会挡住的牛都出栈
   t--;
  sum+=t;//累加结果
  st[++t]=a[i];//入栈操作
 }
 cout<<sum;
 return 0;
}
