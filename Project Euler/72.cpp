#include <iostream>
#define N 1000000
using namespace std;
int phi[N+5],pri[N+5],cnt;
int main()
{
 long long sum=0;
 phi[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!phi[i])
   phi[i]=i-1,pri[++cnt]=i;
  for(int j=1;j<=cnt&&i*pri[j]<=N;j++)
   if(i%pri[j]==0)
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
   else
    phi[i*pri[j]]=phi[i]*phi[pri[j]];
 }
 for(int i=2;i<=N;i++)
  sum+=phi[i];
 cout<<sum<<endl;
 return 0;
}