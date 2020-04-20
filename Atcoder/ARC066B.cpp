#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
map<long long,long long> f;
long long dfs(long long x)
{
 if(f[x])return f[x];
 else return f[x]=(dfs(x/2)+dfs((x-1)/2)+dfs((x-2)/2))%MOD;
}
int main()
{
 long long n;
 cin>>n;
 f[0]=1,f[1]=2;
 cout<<dfs(n)<<endl;
 return 0;
}