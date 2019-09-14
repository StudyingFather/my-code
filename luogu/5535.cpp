/*
 Name: luogu P5535
 Author: StudyingFather
 Date: 2019/09/12 00:13
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
bool is_prime(long long x)
{
 for(long long i=2;i*i<=x;i++)
  if(x%i==0)return false;
 return true;
}
int main()
{
 long long n,k;
 cin>>n>>k;
 if(is_prime(k+1)&&(k+1)*2>n+1)puts("1");
 else puts("2");
 return 0;
}