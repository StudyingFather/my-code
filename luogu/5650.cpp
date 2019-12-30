#include <cstdio>
char s[100005];
int main()
{
 scanf("%s",s);
 int ans=-1,res=0;
 for(int i=0;s[i];i++)
 {
  res+=s[i]=='0'?1:-1;
  if(ans<res)ans=res;
  if(res<0)res=0;
 }
 printf("%d\n",ans);
 return 0;
}