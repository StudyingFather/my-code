// Problem : P5377 [THUPC2019]鸽鸽的分割
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5377
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int main()
{
 int n;
 while(cin>>n)
 {
  int b2=n*(n-1)/2,b4=n*(n-1)*(n-2)*(n-3)/24;
  cout<<1+b2+b4<<endl;
 }
 return 0;
}