/*
 Name: luogu P5601
 Author: StudyingFather
 Date: 2019/10/27 15:40
 Website: https://studyingfather.com
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,string> m;
int main()
{
 int n,q;
 cin>>n>>q;
 while(n--)
 {
  string s,t;
  cin>>s>>t;
  m[s]=t;
 }
 while(q--)
 {
  string s,t;
  cin>>s;
  int ans;
  for(int i=0;i<4;i++)
  {
   cin>>t;
   if(m[s]==t)ans=i;
  }
  cout<<char(ans+'A')<<endl;
 }
 return 0;
}