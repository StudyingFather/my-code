#include <cstdio>
#include <algorithm>
using namespace std;
const int daynum[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int f[100000005],res[6000005],cnt,date[15],num,ans;
char s[15];
inline bool is_run(int y)
{
 if(y%4==0)
 {
  if(y%100==0)
  {
   if(y%400==0)return true;
   return false;
  }
  return true;
 }
 return false;
}
inline bool legal(int y,int m,int d)
{
 if(m>12||m==0||d==0||y==0)return false;
 if(m==2)
 {
  if(is_run(y))
  {
   if(d>29)return false;
   return true;
  }
  else
  {
   if(d>28)return false;
   return true;
  }
 }
 else
 {
  if(d>daynum[m])return false;
  return true;
 }
}
void dfs(int d)
{
 if(d==8)
 {
  int y=num/10000,m=(num%10000)/100,d=num%100;
  if(legal(y,m,d))
   if((!f[d])&&(!f[m*100+d])&&(!f[y*10000+m*100+d]))ans++;
  return;
 }
 if(date[d]!=-1)
 {
  num=num*10+date[d];
  dfs(d+1);
  num/=10;
  return;
 }
 for(int i=0;i<=9;i++)
 {
  if(d==4&&i==2)break;
  if(d==5&&i==0&&date[d-1]==0)continue;
  if(d==5&&date[4]*10+i>12)break;
  if(d==6&&i==4)break;
  date[d]=i;
  num=num*10+i;
  dfs(d+1);
  date[d]=-1;
  num/=10;
 }
}
int main()
{
 int t;
 scanf("%d",&t);
 f[0]=f[1]=1;
 for(long long i=2;i<=99991231;i++)
 {
  if(!f[i])res[++cnt]=i;
  for(long long j=1;j<=cnt&&i*res[j]<=99991231;j++)
  {
   f[i*res[j]]=1;
   if(i%res[j]==0)break;
  }
 }
 while(t--)
 {
  ans=0;
  scanf("%s",s);
  for(int i=0;i<8;i++)
  {
   if(s[i]=='-')date[i]=-1;
   else date[i]=s[i]-'0';
  }
  dfs(0);
  printf("%d\n",ans);
 }
 return 0;
}