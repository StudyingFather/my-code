// Problem : D. Shop
// Contest : Codeforces - Codeforces Round #295 (Div. 1)
// URL : https://codeforces.com/contest/521/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
pii as[100005];
vector<pii> add[100005];
vector<pdi> mul;
vector<int> ans;
int a[100005],op[100005];
bool cmp(int x,int y)
{
 return op[x]<op[y];
}
int main()
{
 int k,n,m;
 cin>>k>>n>>m;
 for(int i=1;i<=k;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
 {
  int x,y;
  cin>>op[i]>>x>>y;
  if(op[i]==1)as[x]=max(as[x],make_pair(y,i));
  if(op[i]==2)add[x].emplace_back(y,i);
  if(op[i]==3)mul.emplace_back(y,i);
 }
 for(int i=1;i<=k;i++)
  if(as[i].first>a[i])
   add[i].emplace_back(as[i].first-a[i],as[i].second);
 for(int i=1;i<=k;i++)
 {
  sort(add[i].begin(),add[i].end(),greater<pii>());
  long long num=a[i];
  for(auto p:add[i])
  {
   mul.emplace_back(1.0*(num+p.first)/num,p.second);
   num+=p.first;
  }
 }
 sort(mul.begin(),mul.end(),greater<pdi>());
 m=min((int)mul.size(),m);
 cout<<m<<endl;
 for(int i=0;i<m;i++)
  ans.push_back(mul[i].second);
 sort(ans.begin(),ans.end(),cmp);
 for(auto x:ans)
  cout<<x<<' ';
 return 0;
}