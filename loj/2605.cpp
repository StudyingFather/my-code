/*
 Name: loj 2605
 Author: StudyingFather
 Date: 2019/08/12 20:19
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
void ex_gcd(long long a,long long b,long long&x,long long&y)
{
 if(b==0)
 {
  x=1,y=0;
  return;
 }
 ex_gcd(b,a%b,x,y);
 int t=x;
 x=y;
 y=t-a/b*y;
 return;
}
int main()
{
 long long a,b,x,y;
 cin>>a>>b;
 ex_gcd(a,b,x,y);
 cout<<(x+b)%b;
 return 0;
}