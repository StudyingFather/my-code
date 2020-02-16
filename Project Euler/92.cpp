#include <cstdio>
#include <cstring>
#define MAXN 10000000
int f[10000005];
int dfs(int x)
{
 if(f[x]!=-1)return f[x];
 int y=0,x1=x;
 while(x1)
 {
  int tmp=x1%10;
  y+=tmp*tmp;
  x1/=10;
 }
 return f[x]=dfs(y);
}
int main()
{
 memset(f,-1,sizeof(f));
 f[1]=0,f[89]=1;
 int ans=0;
 for(int i=2;i<=MAXN;i++)
  f[i]=dfs(i),ans+=f[i];
 printf("%d\n",ans);
 return 0;
}