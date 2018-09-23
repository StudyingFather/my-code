#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[50005],n,d[50005];
bool mark[50010];
int lowbit(int x)
{
 return x&(-x);
}
void add(int i,int x)
{
 while(i<=n)  
 {
  p[i]+=x;
  i+=lowbit(i);
 }
}
int sum(int i)
{
 int sum=0;
 while(i>=1)
 {
  sum+=p[i];
  i-=lowbit(i);
 }
 return sum;
}
int find(int x)
{
 int left=0,right=n+1;
 while(left<right)
 {
  int mid=(left+right)/2;
  if(sum(mid)>=x)right=mid;
  else left=mid+1;
 }
 return right;
}
char str[10];
int main()  
{
 int m,x,cnt; 
 while(~scanf("%d%d",&n,&m))  
 {
  cnt=0;
  memset(p,0,sizeof(p));
  memset(mark,false,sizeof(mark));
  for(int i=1;i<=m;i++)
  {
   scanf("%s",str);
   if(str[0]=='D')
   {
    scanf("%d",&x);
    add(x,1);
    mark[x]=true;
    d[cnt++]=x;
   }
   else if(str[0]=='R')
   {
    x=d[--cnt];
    add(x,-1);
    mark[x]=false;
   }
   else
   {
    scanf("%d",&x);
    if(mark[x]==true)
    {
     printf("0\n");
     continue;
    }
    x=sum(x);
    int a=find(x);
    int b=find(x+1);
    int res=b-a-1;
    printf("%d\n",res);
   }
  }
 }
 return 0;
}
