#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[505];
int f[505][505];
int dfs(int l,int r)
{
 if(f[l][r]!=-1)return f[l][r];
 if(l==r)return f[l][r]=1;
 if(l>r)return f[l][r]=0;
 f[l][r]=1+dfs(l+1,r);
 for(int i=l+1;i<=r;i++)
  if(s[l]==s[i])f[l][r]=min(f[l][r],dfs(l+1,i-1)+dfs(i,r));
 return f[l][r];
}
int main()
{
 int n;
 memset(f,-1,sizeof(f));
 scanf("%d",&n);
 scanf("%s",s);
 printf("%d\n",dfs(0,n-1));
 return 0;
}