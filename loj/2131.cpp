#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int sta,p;
}a[505];
const int pri[]={0,2,3,5,7,11,13,17,19};
long long f[305][305],g1[305][305],g2[305][305];
bool cmp(const node&a,const node&b)
{
 return a.p<b.p;
}
int main()
{
 int n,p;
 long long ans=0;
 cin>>n>>p;
 for(int i=2;i<=n;i++)
 {
  int p=i;
  for(int j=1;j<=8;j++)
  {
   while(p%pri[j]==0)
    p/=pri[j],a[i].sta|=(1<<(j-1));
  }
  a[i].p=p;
 }
 sort(a+2,a+n+1,cmp);
 f[0][0]=1;
 for(int i=2;i<=n;i++)
 {
  if(i==2||a[i].p!=a[i-1].p||a[i].p==1)
  {
   memcpy(g1,f,sizeof(f));
   memcpy(g2,f,sizeof(f));
  }
  for(int j=255;j>=0;j--)
   for(int k=255;k>=0;k--)
   {
    if(j&k)continue;
    if((a[i].sta&k)==0)g1[j|a[i].sta][k]=(g1[j|a[i].sta][k]+g1[j][k])%p;
    if((a[i].sta&j)==0)g2[j][k|a[i].sta]=(g2[j][k|a[i].sta]+g2[j][k])%p;
   }
  if(i==n||a[i].p!=a[i+1].p||a[i].p==1)
   for(int j=0;j<=255;j++)
    for(int k=0;k<=255;k++)
     f[j][k]=((g1[j][k]+g2[j][k]-f[j][k])%p+p)%p;
 }
 for(int j=0;j<=255;j++)
  for(int k=0;k<=255;k++)
   if((j&k)==0)ans=(ans+f[j][k])%p;
 cout<<ans<<endl;
 return 0;
}