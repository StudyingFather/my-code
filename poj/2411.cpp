#include <iostream>
using namespace std;
long long f[15][2055];
bool s[2055];
int main()
{
 int m,n;
 while(cin>>m>>n&&m&&n)
 {
  for(int i=0;i<=1<<m;i++)
  {
   bool cnt=0,odd=0;
   for(int j=0;j<m;j++)
    if(i>>j&1)
    {
   	 odd|=cnt;
   	 cnt=0;
    }
    else cnt^=1;
   s[i]=!(odd|cnt);
  }
  f[0][0]=1;
  for(int i=1;i<=n;i++)
   for(int j=0;j<1<<m;j++)
   {
   	f[i][j]=0;
   	for(int k=0;k<1<<m;k++)
   	 if(!(j&k)&&s[j|k])f[i][j]+=f[i-1][k];
   }
  cout<<f[n][0]<<endl;
 }
 return 0;
}
