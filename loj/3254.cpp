// Problem : #3254. 「JOI 2020 Final」集邮比赛 3
// Contest : LibreOJ
// URL : https://loj.ac/problem/3254
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
 int l,r,p,d;
};
queue<node> q;
int f[405][405][205][2];
bool vis[405][405][205][2];
int x[405],t[405];
int main()
{
 int n,L,ans=0;
 cin>>n>>L;
 for(int i=1;i<=n;i++)
  cin>>x[i],x[i+n+1]=x[i]+L;
 for(int i=1;i<=n;i++)
  cin>>t[i],t[i+n+1]=t[i];
 x[n+1]=L;
 t[n+1]=-1;
 memset(f,63,sizeof(f));
 f[n+1][n+1][0][0]=0;
 q.push({n+1,n+1,0,0});
 while(!q.empty())
 {
  int l=q.front().l,r=q.front().r,p=q.front().p,d=q.front().d;
  ans=max(ans,p);
  q.pop();
  vis[l][r][p][d]=0;
  int nl=l-1,nr=r+1;
  if(!d)
  {
   int nt=f[l][r][p][d]+abs(x[nl]-x[l]);
   if(nt<f[nl][r][p+(nt<=t[nl])][0]&&r-nl<=n)
   {
    f[nl][r][p+(nt<=t[nl])][0]=nt;
    if(!vis[nl][r][p+(nt<=t[nl])][0])
     q.push({nl,r,p+(nt<=t[nl]),0});
   }
   nt=f[l][r][p][d]+abs(x[nr]-x[l]);
   if(nt<f[l][nr][p+(nt<=t[nr])][1]&&nr-l<=n)
   {
    f[l][nr][p+(nt<=t[nr])][1]=nt;
    if(!vis[l][nr][p+(nt<=t[nr])][1])
     q.push({l,nr,p+(nt<=t[nr]),1});
   }
  }
  else
  {
   int nt=f[l][r][p][d]+abs(x[nl]-x[r]);
   if(nt<f[nl][r][p+(nt<=t[nl])][0]&&r-nl<=n)
   {
    f[nl][r][p+(nt<=t[nl])][0]=nt;
    if(!vis[nl][r][p+(nt<=t[nl])][0])
     q.push({nl,r,p+(nt<=t[nl]),0});
   }
   nt=f[l][r][p][d]+abs(x[nr]-x[r]);
   if(nt<f[l][nr][p+(nt<=t[nr])][1]&&nr-l<=n)
   {
    f[l][nr][p+(nt<=t[nr])][1]=nt;
    if(!vis[l][nr][p+(nt<=t[nr])][1])
     q.push({l,nr,p+(nt<=t[nr]),1});
   }
  }
 }
 cout<<ans<<endl;
 return 0;
}