#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string re;
int main()
{
 for(int i=0;i<=9;i++)
 {
  cout<<i<<endl;
  fflush(stdout);
  getline(cin,re);
  if(re=="no")continue;
  else if(re=="great"||re=="not bad"||re=="cool"||re=="don't touch me"||re=="don't think so")cout<<"normal";
  else cout<<"grumpy";
  fflush(stdout);
  return 0;
 }
}
