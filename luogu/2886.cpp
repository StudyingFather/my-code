/*
 Name: luogu P2886
 Author: StudyingFather
 Date: 2019/10/31 23:32
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct mat
{
 long long a[205][205];
 mat(int x=0)
 {
  memset(a,x,sizeof(a));
 }
}f(63),ans(63);
int tot,m[1005];
mat operator*(mat a,mat b)
{
 mat c(63);
 for(int k=1;k<=tot;k++)
  for(int i=1;i<=tot;i++)
   for(int j=1;j<=tot;j++)
    c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
 return c;
}
int main()
{
 int n,t,s,e;
 cin>>n>>t>>s>>e;
 for(int i=1;i<=t;i++)
 {
  int w,u,v;
  cin>>w>>u>>v;
  if(!m[u])m[u]=++tot;
  if(!m[v])m[v]=++tot;
  f.a[m[u]][m[v]]=f.a[m[v]][m[u]]=w;
 }
 for(int i=1;i<=tot;i++)
  ans.a[i][i]=0;
 while(n)
 {
  if(n&1)ans=ans*f;
  f=f*f;
  n>>=1;
 }
 cout<<ans.a[m[s]][m[e]]<<endl;
 return 0;
}