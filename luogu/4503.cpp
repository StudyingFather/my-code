#include <cstdio>
#include <cstring>
#include <algorithm>
#define BIG1 19260817
#define BIG2 19491001
using namespace std;
char str[205];
unsigned long long f[30005][205],g[30005][205],tmp[30005];
int main()
{
 int n,l,s,ans=0;
 scanf("%d%d%d",&n,&l,&s);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",str+1);
  for(int j=1;j<=l;j++)
   f[i][j]=f[i][j-1]*BIG1+str[j];
  for(int j=l;j>=1;j--)
   g[i][j]=g[i][j+1]*BIG2+str[j];
 }
 for(int i=1;i<=l;i++)
 {
  for(int j=1;j<=n;j++)
   tmp[j]=f[j][i-1]*233+g[j][i+1]*323;
  sort(tmp+1,tmp+n+1);
  int num=1;
  for(int j=2;j<=n;j++)
  {
   if(tmp[j]==tmp[j-1])ans+=num,num++;
   else num=1;
  }
 }
 printf("%d\n",ans);
 return 0;
}