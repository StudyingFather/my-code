/*
 Name: CodeChef CATFEED
 Author: StudyingFather
 Date: 2019/10/06 20:45
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
int f[105];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,m;
  memset(f,0,sizeof(f));
  scanf("%d%d",&n,&m);
  bool res=true;
  for(int i=1;i<=m;i++)
  {
   int x;
   scanf("%d",&x);
   bool flag=true;
   for(int j=1;j<=n;j++)
    if(f[x]>f[j])flag=false;
   f[x]++;
   res&=flag;
  }
  puts(res?"YES":"NO");
 }
 return 0;
}