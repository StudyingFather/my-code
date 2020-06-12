// Problem : P6582 座位调查
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6582
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define MOD 998244353
using namespace std;
int cnt,c1;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char s[1005][1005];
int vis[1005][1005];
void dfs(int x,int y)
{
 cnt++,vis[x][y]=1;
 int deg=0;
 for(int i=0;i<4;i++)
 {
  int nx=x+dx[i],ny=y+dy[i];
  if(s[nx][ny]=='O')
  {
   deg++;
   if(!vis[nx][ny])dfs(nx,ny);
  }
 }
 c1+=(deg==1);
}
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 int n,m,k;
 long long ans=1;
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
  cin>>(s[i]+1);
 for(int x=1;x<=n;x++)
  for(int y=1;y<=m;y++)
   if(!vis[x][y]&&s[x][y]=='O')
   {
    c1=0,cnt=0,dfs(x,y);
    if(c1==2||cnt==1)ans=ans*k%MOD*fpow(k-1,cnt-1)%MOD;
    else ans=0;
   }
 cout<<ans<<endl;
 return 0;
}