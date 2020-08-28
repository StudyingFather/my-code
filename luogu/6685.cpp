// Problem: P6685 可持久化动态仙人掌的直径问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6685
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
long long fpow(int x,int y)
{
 long long ans=1;
 while(y--)
  ans*=x;
 return ans;
}
int main()
{
 int n,m;
 cin>>n>>m;
 if(m>=32)
  cout<<1<<endl;
 else
  for(int i=1;;i++)
   if(fpow(i,m)>n)
   {
    cout<<i-1<<endl;
    return 0;
   }
}