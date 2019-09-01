/*
 Name: luogu P1466
 Author: StudyingFather
 Date: 2019/08/24 15:17
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
long long f[1005];
int main()
{
 int n;
 cin>>n;
 f[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=n*(n+1)/2;j>=i;j--)
   f[j]+=f[j-i];
 if(n*(n+1)%4)cout<<0<<endl;
 else cout<<f[n*(n+1)/4]/2<<endl;
 return 0;
}