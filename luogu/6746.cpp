// Problem: P6746 『MdOI R3』Operations
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6746
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 if(a==0&&b==0)cout<<0<<endl;
 else if(a==0||b==0)cout<<d<<endl;
 else if(a==b)cout<<min(c,2*d)<<endl;
 else cout<<min(c+d,2*d)<<endl;
 return 0;
}