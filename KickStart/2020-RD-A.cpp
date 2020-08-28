// Problem : Record Breaker
// Contest : Google Coding Competitions - Round D 2020 - Kick Start 2020
// URL : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
// Memory Limit : 1024 MB
// Time Limit : 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstring>
int a[200005];
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  memset(a,0,sizeof(a));
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  a[n+1]=-1;
  int maxa=-1,ans=0;
  for(int i=1;i<=n;i++)
  {
   if(a[i]>maxa)
   {
    if(a[i]>a[i+1])
     ans++;
    maxa=a[i];
   }
  }
  printf("Case #%d: %d\n",kase,ans);
 }
 return 0;
}