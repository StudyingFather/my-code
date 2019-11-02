/*
 Name: loj 6342
 Author: StudyingFather
 Date: 2019/10/29 16:54
 Website: https://studyingfather.com
*/
#include <iostream>
#define MOD 1000000007
using namespace std;
int inv[10000005];
int main()
{
 int n;
 cin>>n;
 inv[1]=1;
 for(int i=2;i<=n;i++)
  inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
 long long sum=0,f=0;
 for(int i=2;i<=n;i++)
  f=(1ll*i*inv[i-1]+1ll*sum*inv[i-1])%MOD,sum=(sum+f)%MOD;
 cout<<f<<endl;
 return 0;
}