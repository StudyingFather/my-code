/*
 Name: Atcoder Beginner Contest 144C
 Author: StudyingFather
 Date: 2019/10/27 21:07
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
int main()
{
 long long n;
 cin>>n;
 long long maxp;
 for(maxp=1;maxp*maxp<=n;maxp++)
  ;
 maxp--;
 for(long long i=maxp;i;i--)
  if(n%i==0)
  {
   cout<<(i-1)+(n/i-1)<<endl;
   return 0;
  }
}