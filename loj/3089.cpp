// Problem : #3089. 「BJOI2019」奥术神杖
// Contest : LibreOJ
// URL : https://loj.ac/problem/3089
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cmath>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
const double eqs=1e-6;
const int sigma=10;
string s[1505],t;
int n,m;
int tr[1505][sigma],fail[1505],cnt;
double val[1505];
int sum[1505];
double f[1505][1505];
char ans[1505];
pair<int,int> g[1505][1505];
void insert(string s,double x)
{
 int u=0;
 for(auto c:s)
 {
  if(!tr[u][c-'0'])
   tr[u][c-'0']=++cnt;
  u=tr[u][c-'0'];
 }
 sum[u]++,val[u]+=x;
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
  sum[u]+=sum[fail[u]],val[u]+=val[fail[u]];
  for(int i=0;i<sigma;i++)
  {
   if(tr[u][i])
    fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
   else
    tr[u][i]=tr[fail[u]][i];
  }
 }
}
bool check(double x)
{
 for(int i=0;i<=cnt;i++)
  val[i]-=x*sum[i];
 for(int i=0;i<=n;i++)
  for(int j=0;j<=cnt;j++)
   f[i][j]=-1e100;
 f[0][0]=0;
 for(int i=0;i<n;i++)
  for(int j=0;j<=cnt;j++)
   for(int k=0;k<sigma;k++)
    if(t[i]=='.'||t[i]==k+'0')
    {
     int v=tr[j][k];
     if(f[i][j]+val[v]>f[i+1][v])
     {
      f[i+1][v]=f[i][j]+val[v];
      g[i+1][v]=make_pair(j,k);
     }
    }
 double res=-1e100;
 int pos=0;
 for(int i=0;i<=cnt;i++)
 {
  if(f[n][i]>res)
   res=f[n][i],pos=i;
 }
 for(int i=n;i;i--)
 {
  ans[i-1]=g[i][pos].second+'0';
  pos=g[i][pos].first;
 }
 for(int i=0;i<=cnt;i++)
  val[i]+=x*sum[i];
 return res>0;
}
int main()
{
 cin>>n>>m;
 cin>>t;
 for(int i=1;i<=m;i++)
 {
  double v;
  cin>>s[i]>>v;
  insert(s[i],log(v));
 }
 build();
 double l=0,r=log(1e9);
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))l=mid;
  else r=mid;
 }
 check(l);
 cout<<ans<<endl;
 return 0;
}