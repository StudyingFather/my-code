// Problem : P4052 [JSOI2007]文本生成器
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4052
// Memory Limit : 128 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
#include <queue>
#define MOD 10007
using namespace std;
const int sigma=26;
int tr[6005][sigma],fail[6005],cnt;
int vis[6005];
int f[105][6005];
int fpow(int x,int y)
{
 int ans=1;
 while(y--)
  ans=ans*x%MOD;
 return ans;
}
void insert(string s)
{
 int u=0;
 for(auto c:s)
 {
  if(!tr[u][c-'A'])
   tr[u][c-'A']=++cnt;
  u=tr[u][c-'A'];
 }
 vis[u]=1;
}
void build()
{
 queue<int> q;
 for(int i=0;i<sigma;i++)
  if(tr[0][i])q.push(tr[0][i]);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=0;i<sigma;i++)
  {
   if(tr[u][i])
   {
    fail[tr[u][i]]=tr[fail[u]][i];
    vis[tr[u][i]]|=vis[fail[tr[u][i]]];
    q.push(tr[u][i]);
   }
   else
    tr[u][i]=tr[fail[u]][i];
  }
 }
}
int main()
{
 int n,m;
 cin>>n>>m;
 int ans=fpow(26,m);
 for(int i=1;i<=n;i++)
 {
  string s;
  cin>>s;
  insert(s);
 }
 build();
 f[0][0]=1;
 for(int i=0;i<m;i++)
  for(int j=0;j<=cnt;j++)
   for(int k=0;k<sigma;k++)
    if(!vis[tr[j][k]])
     f[i+1][tr[j][k]]=(f[i+1][tr[j][k]]+f[i][j])%MOD;
 for(int i=0;i<=cnt;i++)
  ans=(ans-f[m][i]+MOD)%MOD;
 cout<<ans<<endl;
 return 0;
}