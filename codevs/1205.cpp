#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<string> a;
string str,s;
int n;
int main()
{
 while(cin>>str)
 {
  a.push(str);
  n++;
 }
 while(n--)
 {
  s=a.top();
  cout<<s<<' ';
  a.pop();
 }
 return 0;
}
