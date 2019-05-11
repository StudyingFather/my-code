#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[11000005],s[25000005];
int f[25000005];
void init()
{
 s[0]=s[1]='#';//0位置防止越界
 int len=strlen(a);
 for(int i=0;i<len;i++)
 {
  s[2*i+2]=a[i];
  s[2*i+3]='#';
 }
 s[2*len+2]=0;
}
int main()
{
 int ans=0;
 scanf("%s",a);
 init();
 int len=strlen(s),maxr=0,mid=0;
 for(int i=1;i<len;i++)
 {
  if(i<maxr)
   f[i]=min(f[mid]+(mid-i),f[mid*2-i]);
  else f[i]=1;
  while(s[i+f[i]]==s[i-f[i]])
   f[i]++;
  if(f[i]+i>maxr)
  {
   maxr=f[i]+i;
   mid=i;
  }
  ans=max(ans,f[i]);
 }
 printf("%d\n",ans-1);
 return 0;
}