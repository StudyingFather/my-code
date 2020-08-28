// Problem : P6625 [省选联考 2020 B 卷] 卡牌游戏
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6625
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int a[100005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 long long ans=0,sum=0;
 for(int i=1;i<=n;i++)
 {
  sum+=a[i];
  if(sum>0&&i!=1)
   ans+=sum;
 }
 cout<<ans<<endl;
 return 0;
}