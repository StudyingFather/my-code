#include <cstdio>
char s[15];
int res[15];
int main()
{
 scanf("%s",s);
 if(s[0]!='M'||s[1]!='D'||s[2]!='A')
 {
  for(int i=1;i<=5;i++)
   res[i]=1;
 }
 else
  for(int i=7;i;i--)
  {
   if(s[i]>='0'&&s[i]<='9')
   {
    int d=s[i]-'0';
    if(d>=1&&d<=5)res[d]=1;
    else if(!d)res[5]=1;
    else res[10-d]=1;
    break;
   }
  }
 for(int i=1;i<=5;i++)
  printf("%d ",res[i]);
 return 0;
}