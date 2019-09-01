/*
 Name: luogu P1326
 Author: StudyingFather
 Date: 2019/08/02 18:46
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
int main()
{
 long long s,t,n;
 while(cin>>s>>t>>n)
 {
  if(s>=n)
  {
   if(s-n+1>t)cout<<3*n<<' ';
   else if(s-n+1==t)cout<<3*n-2<<' ';
   else cout<<3*n-3<<' ';
  }
  else cout<<3*s+n-s-1+(t==0)<<' ';
  if(s>t)cout<<max(3ll,3+n-t-1)<<endl;
  else cout<<min(max(3ll,3-t+n-1),((t-s)>=n?0:n-t+s))<<endl;
 }
 return 0;
}