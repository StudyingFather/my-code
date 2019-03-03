#include <cstdio>
#include <algorithm>
#include <unordered_map>//一定要以c++11标准编译
#include <cstring>
using namespace std;
unordered_map<int,int> num;//利用hash的unordered_map可以大大降低常数
int fa[200005];
int tj[100005][2];
int find(int a)//用递归写会爆栈，所以这里用非递归写了 
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
   if(num[i]==0)num[i]=++cnt;//map大法好，但常数确实大了 
   if(num[j]==0)num[j]=++cnt;//可以试试unordered_map？ 
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
