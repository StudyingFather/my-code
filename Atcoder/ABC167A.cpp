// Problem : A - Registration
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
using namespace std;
string s,t;
int main()
{
 cin>>s>>t;
 int l=s.length();
 for(int i=0;i<l;i++)
  if(s[i]!=t[i])
  {
   cout<<"No"<<endl;
   return 0;
  }
 cout<<"Yes"<<endl;
 return 0;
}