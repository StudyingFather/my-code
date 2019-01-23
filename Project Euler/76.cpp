#include <iostream>
#include <cstring>
#include <cmath>
#define MAXN 100
using namespace std;
int f[105][105],ans;
int main()
{
 for(int i=0;i<=MAXN;i++)
  f[i][1]=1,f[i][i]=1;
 for(int i=2;i<=MAXN;i++)
  for(int j=1;j<=i;j++)
   f[i][j]=f[i-1][j-1]+f[i-j][j];
 for(int i=2;i<=MAXN;i++)//应该至少被拆分成两个数
  ans+=f[MAXN][i];
 cout<<ans;
 return 0;
}
