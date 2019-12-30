#include <iostream>
#include <algorithm>
#define N 50000
using namespace std;
long long mu[50005],pri[50005],vis[50005],s[50005];
void init()
{
 int cnt=0;
 mu[1]=vis[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!vis[i])
  {
   mu[i]=-1;
   pri[++cnt]=i;
  }
  for(int j=1;j<=cnt&&i*pri[j]<=N;j++)
  {
   vis[i*pri[j]]=1;
   if(i%pri[j]==0)
   {
    mu[i*pri[j]]=0;
    break;
   }
   mu[i*pri[j]]=-mu[i];
  }
 }
 for(int i=1;i<=N;i++)
  mu[i]+=mu[i-1];
 for(int i=1;i<=N;i++)
 {
  long long res=0;
  for(int l=1,r;l<=i;l=r+1)
  {
   r=i/(i/l);
   res+=1ll*(r-l+1)*(i/l);
  }
  s[i]=res;
 }
}
int main()
{
 int t;
 cin>>t;
 init();
 while(t--)
 {
  int x,y;
  cin>>x>>y;
  if(x>y)swap(x,y);
  long long ans=0;
  for(int l=1,r;l<=x;l=r+1)
  {
   r=min(x/(x/l),y/(y/l));
   ans+=1ll*(mu[r]-mu[l-1])*s[x/l]*s[y/l];
  }
  cout<<ans<<endl;
 }
 return 0;
}