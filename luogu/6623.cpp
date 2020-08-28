// Problem : P6623 [省选联考 2020 A 卷] 树
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6623
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
using namespace std;
int v[600005],n;
int a[2500005][25];
vector<int> e[600005];
long long sum;
int dfs(int u,int d)
{
 int ans=v[u];
 for(int i=0;i<=20;i++)
  a[(d+v[u])&((1<<i)-1)][i]^=1<<i;
 for(int i=0;i<=20;i++)
  ans^=a[d&((1<<i)-1)][i];
 for(auto v:e[u])
  ans^=dfs(v,d+1);
 for(int i=0;i<=20;i++)
  ans^=a[d&((1<<i)-1)][i];
 sum+=ans;
 return ans;
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>v[i];
 for(int i=2;i<=n;i++)
 {
  int fa;
  cin>>fa;
  e[fa].push_back(i);
 }
 dfs(1,0);
 cout<<sum<<endl;
 return 0;
}