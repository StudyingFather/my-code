/*
 Name: Codeforces 1216D
 Author: StudyingFather
 Date: 2019/09/26 21:48
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005],d[200005];
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n+1);
 int gcdnum=a[n]-a[1];
 long long dsum=0;
 for(int i=1;i<n;i++)
 {
  d[i]=a[n]-a[i];
  gcdnum=gcd(gcdnum,d[i]);
  dsum+=d[i];
 }
 cout<<dsum/gcdnum<<' '<<gcdnum<<endl;
 return 0;
}