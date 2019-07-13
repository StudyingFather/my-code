#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[55];
int n,f[55][55];
int dfs(int l,int r)
{
 if(l==r)return f[l][r]=1;
 if(~f[l][r])return f[l][r];
 if(s[l]==s[r])return f[l][r]=min(dfs(l,r-1),dfs(l+1,r));
 int res=55;
 for(int k=l;k<r;k++)
  res=min(res,dfs(l,k)+dfs(k+1,r));
 return f[l][r]=res;
}
int main()
{
 scanf("%s",s+1);
 n=strlen(s+1);
 memset(f,-1,sizeof(f));
 printf("%d\n",dfs(1,n));
 return 0;
}