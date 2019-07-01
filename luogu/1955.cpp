#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;
unordered_map<int,int> num;
int fa[200005];
int tj[100005][2];
int find(int a)
{
 int r=a;
 while(r!=fa[r])
  r=fa[r];
 int i=a,j;
 while(i!=r)
 {
  j=fa[r];
  fa[i]=r;
  i=j;
 }
 return r;
}
void unionn(int i,int j)
{
 fa[j]=i;
}
void setfa()
{
 for(int i=1;i<=200000;i++)
  fa[i]=i;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int cnt=0,cntt=0;
  num.clear();
  memset(tj,0,sizeof(tj));
  setfa();
  int n;
  scanf("%d",&n);
  for(int k=1;k<=n;k++)
  {
   int i,j,e;
   scanf("%d%d%d",&i,&j,&e);
   if(num[i]==0)num[i]=++cnt;
   if(num[j]==0)num[j]=++cnt;
   if(e)unionn(find(num[i]),find(num[j]));
   else
   {
    cntt++;
    tj[cntt][0]=num[i];
    tj[cntt][1]=num[j];
   }
  }
  int flag=1;
  for(int i=1;i<=cntt;i++)
   if(find(tj[i][0])==find(tj[i][1]))
   {
    puts("NO");
    flag=0;
    break;
   }
  if(flag)puts("YES");
 }
 return 0;
}
