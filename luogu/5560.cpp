/*
 Name: luogu P5560
 Author: StudyingFather
 Date: 2019/09/19 23:32
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
  long long n;
  cin>>n;
  if(n==4||n==10)cout<<n+1<<endl;
  else cout<<n-1<<endl;
 }
 return 0;
}