#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
char s[505];
bool str[505][505],flag2;
int main()
{
 scanf("%d%d",&n,&m);
 bool flag1=0;
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s+1);
  for(int j=1;j<=m;j++)
  {
   if(s[j]=='*')
    str[i][j]=1,flag1=1;
  }
 }
 if(!flag1)
 {
  puts("NO");
  return 0;
 }
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   if(str[i][j])
   {
    int p=i-1,res=0;
    while(str[p][j]&&p)
     p--,res|=1;
    p=j-1;
    while(str[i][p]&&p)
     p--,res|=2;
    p=i+1;
    while(str[p][j]&&p<=n)
     p++,res|=4;
    p=j+1;
    while(str[i][p]&&p<=m)
     p++,res|=8;
    if(res==15)
    {
     if(flag2)
     {
      puts("NO");
      return 0;
     }
     str[i][j]=0;
     p=i-1;
     while(str[p][j]&&p)
      str[p][j]=0,p--;
     p=j-1;
     while(str[i][p]&&p)
      str[i][p]=0,p--;
     p=i+1;
     while(str[p][j]&&p<=n)
      str[p][j]=0,p++;
     p=j+1;
     while(str[i][p]&&p<=m)
      str[i][p]=0,p++;
     flag2=1;
     for(int k=1;k<=n;k++)
      for(int l=1;l<=m;l++)
       if(str[k][l])
       {
        puts("NO");
        return 0;
       }
    }
   }
 }
 if(flag2)puts("YES");
 else puts("NO");
 return 0;
}