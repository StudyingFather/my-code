// Problem : #2833. 「JOISC 2018 Day 1」帐篷
// Contest : LibreOJ
// URL : https://loj.ac/problem/2833
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define MOD 1000000007
using namespace std;
long long f[3005][3005];
int main()
{
 int h,w;
 cin>>h>>w;
 for(int i=0;i<=h;i++)
  f[i][0]=1;
 for(int i=0;i<=w;i++)
  f[0][i]=1;
 for(int i=1;i<=h;i++)
  for(int j=1;j<=w;j++)
  {
   f[i][j]=f[i-1][j];
   f[i][j]=(f[i][j]+4*j*f[i-1][j-1])%MOD;
   if(i>=2)
    f[i][j]=(f[i][j]+f[i-2][j-1]*j*(i-1))%MOD;
   if(j>=2)
    f[i][j]=(f[i][j]+f[i-1][j-2]*j*(j-1)/2)%MOD;
  }
 cout<<(f[h][w]-1+MOD)%MOD<<endl;
 return 0;
}