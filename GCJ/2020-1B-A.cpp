// Problem : Expogo
// Contest : Google Coding Competitions - Round 1B 2020 - Code Jam 2020
// URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
// Memory Limit : 1024 MB
// Time Limit : 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long pow2[55];
char res[55];
int calc(int x)
{
 int cnt=0;
 while(x)
  x>>=1,cnt++;
 return cnt;
}
int main()
{
 int t;
 scanf("%d",&t);
 pow2[1]=1;
 for(int i=2;i<=40;i++)
  pow2[i]=pow2[i-1]*2;
 for(int kase=1;kase<=t;kase++)
 {
  memset(res,0,sizeof(res));
  int x,y;
  scanf("%d%d",&x,&y);
  printf("Case #%d: ",kase);
  if((x+y)%2==0)
  {
   puts("IMPOSSIBLE");
   continue;
  }
  int t=calc(abs(x)+abs(y));
  long long tx=0,ty=0;
  for(int i=t;i;i--)
  {
   if(abs(tx-x)>abs(ty-y))
   {
    if(tx-x>0)res[i]='W',x=x+pow2[i];
    else res[i]='E',x=x-pow2[i];
   }
   else
   {
    if(ty-y>0)res[i]='S',y=y+pow2[i];
    else res[i]='N',y=y-pow2[i];
   }
  }
  puts(res+1);
 }
 return 0;
}