/*
 Name: luogu P2350
 Author: StudyingFather
 Date: 2019/10/16 16:43
 Website: https://studyingfather.com
*/
#include <iostream>
#include <cstring>
using namespace std;
int vis[100005],f[100005],pri[100005],cnt;
int main()
{
 int t;
 cin>>t;
 memset(vis,0,sizeof(vis));
 f[1]=1;
 for(int i=2;i<=100000;i++)
 {
  if(!vis[i])pri[++cnt]=i,f[i]=f[i-1];
  for(int j=1;j<=cnt&&i*pri[j]<=100000;j++)
  {
   vis[i*pri[j]]=1;
   f[i*pri[j]]=f[i]+f[pri[j]];
   if(i%pri[j]==0)break;
  }
 }
 while(t--)
 {
  int m;
  bool flag=true;
  cin>>m;
  long long ans=0;
  for(int i=1;i<=m;i++)
  {
   int p,q;
   cin>>p>>q;
   if(p==2)flag=false;
   ans+=1ll*f[p]*q;
  }
  cout<<ans+flag<<endl;
 }
 return 0;
}