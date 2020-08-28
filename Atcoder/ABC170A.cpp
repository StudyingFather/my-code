// Problem : A - Five Variables
// Contest : AtCoder - AtCoder Beginner Contest 170
// URL : https://atcoder.jp/contests/abc170/tasks/abc170_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int main()
{
 for(int i=1;i<=5;i++)
 {
  int x;
  cin>>x;
  if(x==0)cout<<i<<endl;
 }
 return 0;
}