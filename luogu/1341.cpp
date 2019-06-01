#include <cstdio>
#include <algorithm>
using namespace std;
int f[205][205],t[205],cnte;
char a[2],res[205];
void dfs(int x)
{
 for(int i=65;i<=122;i++)
  if(f[x][i])
  {
   f[x][i]=f[i][x]=0;
   dfs(i);
  }
 res[++cnte]=x;
}
int main()
{
 int n,cnts=0,s;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",a);
  f[a[0]][a[1]]=f[a[1]][a[0]]=1;
  t[a[0]]++,t[a[1]]++;
 }
 for(int i=65;i<=122;i++)
  if(t[i]%2)
  {
   if(!cnts)s=i;
   cnts++;
  }
 if(!cnts)
  for(int i=65;i<=122;i++)
   if(t[i])
   {
    s=i;
    break;
   }
 dfs(s);
 if(cnte!=n+1||cnts>2)puts("No Solution");
 else
  for(int i=n+1;i;i--)
   putchar(res[i]);
 return 0;
}