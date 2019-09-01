/*
 Name: luogu P1474
 Author: StudyingFather
 Date: 2019/08/24 15:27
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
long long f[10005];
int a[55],v,n;
int main()
{
 cin>>v>>n;
 for(int i=1;i<=v;i++)
  cin>>a[i];
 f[0]=1;
 for(int i=1;i<=v;i++)
  for(int j=a[i];j<=n;j++)
   f[j]+=f[j-a[i]];
 cout<<f[n]<<endl;
 return 0;
}