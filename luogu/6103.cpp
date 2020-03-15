#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull f[10005],g[10005];
int main()
{
 int n;
 cin>>n;
 f[0]=g[1]=1;
 for(int i=1;i<=n;i++)
 {
  f[i]=f[i-1];
  for(int j=0;i-j-2>=0;j++)
   f[i]+=f[i-j-2]*f[j];
  for(int j=0;i-j-4>=0;j++)
   f[i]+=g[i-j-4]*f[j];
  for(int j=1;i+1-j>=0;j+=2)
   g[i+1]+=f[i+1-j]*j;
 }
 cout<<f[n]<<endl;
 return 0;
}