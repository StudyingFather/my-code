#include <stdio.h>
char a[20];
int main()
{
 scanf("%s",a);
 int ans=0,number=1;
 for(int i=0;i<12;i++)
  if(a[i]!='-')
  {
   ans+=(a[i]-'0')*number;
   number++;
  }
 ans%=11;
 if(ans==(a[12]-'0')||(ans==10&&a[12]=='X'))
 {
  puts("Right");
  return 0;
 }
 else if(ans==10)a[12]='X';
 else a[12]=ans+'0';
 printf("%s",a);
 return 0;
}
