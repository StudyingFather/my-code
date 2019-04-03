#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n;
  bool flag=false;
  scanf("%d",&n);
  scanf("%s",s);
  for(int i=0;i<n;i++)
   if(s[i]=='>'||s[n-i-1]=='<')
   {
    printf("%d\n",i);
    flag=true;
    break;
   }
  if(!flag)printf("%d\n",n-1);
 }
 return 0;
}