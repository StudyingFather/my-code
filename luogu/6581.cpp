// Problem : P6581 远大目标
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6581
// Memory Limit : 128 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int main()
{
 long long x;
 cin>>x;
 if(x>0)cout<<2ull*x-1<<endl;
 else cout<<0<<endl;
 return 0;
}