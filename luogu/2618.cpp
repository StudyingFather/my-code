/*
 Name: luogu P2618
 Author: StudyingFather
 Date: 2019/09/26 00:10
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int f[1000005],vis[1000005],pri[1000005],cnt;
int main()
{
 for(int i=2;i<=1000000;i++)
 {
  if(vis[i])continue;
  pri[++cnt]=i;
  q.push(i),f[i]=1;
  for(long long j=i;j*i<=1000000;j++)
   vis[j*i]=1;
 }
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  if(!f[u+1])
   f[u+1]=f[u]+1,q.push(u+1);
  for(long long i=1;u*pri[i]<=1000000;i++)
   if(!f[u*pri[i]])
    f[u*pri[i]]=f[u]+1,q.push(u*pri[i]);
 }
 int n;
 while(cin>>n)
  cout<<f[n]<<endl;
 return 0;
}