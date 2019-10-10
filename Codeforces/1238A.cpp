/*
 Name: Codeforces 1238A
 Author: StudyingFather
 Date: 2019/09/25 22:37
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long x,y;
  cin>>x>>y;
  if(x-y!=1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
 }
 return 0;
}