
// Problem : B - Crane and Turtle
// Contest : AtCoder - AtCoder Beginner Contest 170
// URL : https://atcoder.jp/contests/abc170/tasks/abc170_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int main()
{
 int x,y;
 cin>>x>>y;
 for(int i=0;i<=x;i++)
  if(2*i+4*(x-i)==y)
  {
   cout<<"Yes"<<endl;
   return 0;
  }
 cout<<"No"<<endl;
 return 0;
}