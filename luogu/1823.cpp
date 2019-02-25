#include <iostream>
#include <algorithm>
using namespace std;
int a[500005],st[500005];
int t;
long long sum;
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  int cnt=1;
  while(t&&st[t]<=a[i])
  {
   if(st[t]==a[i])cnt++;
   sum++,t--;
  }
  if(t)sum++;
  while(cnt--)
   st[++t]=a[i];
 }
 cout<<sum<<endl;
 return 0;
}