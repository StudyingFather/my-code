#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int b[305],f[2][90005];
int main()
{
 int n,m,k,suma=0,sumb=0;
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  if(x<k)
  {
   cout<<"Impossible"<<endl;
   return 0;
  }
  suma+=x;
 }
 for(int i=1;i<=m;i++)
  cin>>b[i];
 memset(f,191,sizeof(f));
 f[0][0]=0;
 for(int i=1;i<=m;i++)
 {
  int p=i&1,q=p^1;
  for(int j=0;j<b[i];j++)
   f[p][j]=f[q][j];
  sumb+=b[i];
  for(int j=b[i];j<=sumb;j++)
   f[p][j]=max(f[q][j],f[q][j-b[i]]+min(b[i],n));
 }
 for(int i=suma;i<=sumb;i++)
  if(f[m&1][i]>=n*k)
  {
   cout<<i-suma<<endl;
   return 0;
  }
 cout<<"Impossible"<<endl;
 return 0;
}