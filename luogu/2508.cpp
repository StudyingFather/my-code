/*
 Name: luogu P2508
 Author: StudyingFather
 Date: 2019/10/06 21:53
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
int g(int x,int y)
{
 if(!y)return 1;
 if(x%2==0)return 1;
 if(x%4==1)return y+1;
 if(x%4==3)return y%2==0;
}
long long f(long long n)
{
 long long ans=4;
 int tmp=n;
 for(int cur=2;cur*cur<=n;cur++)
 {
  int num=0;
  while(tmp%cur==0)
   tmp/=cur,num++;
  ans*=g(cur,num*2);
 }
 if(tmp!=1)ans*=g(tmp,2);
 return ans;
}
int main()
{
 long long n;
 cin>>n;
 cout<<f(n)<<endl;
 return 0;
}