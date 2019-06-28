#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[155];
int len,a,b;
int main()
{
 while(fgets(s,155,stdin))
 {
  len=strlen(s);
  for(int i=0;i<len;i++)
  { 
   if(s[i]>48&&s[i]<58)
   {
    b=s[i]-'0';
    a+=b;
   }
   else
   {
    if(s[i]=='b')
     for(int j=1;j<=a;j++) 
      printf(" ");
    else
    {
     if(s[i]=='!') 
      printf("\n");
     else
      for(int j=1;j<=a;j++)
       printf("%c",s[i]);
    }
    a=0;
   }
   if(i==len-1)printf("\n");
  }
 }
 return 0;
}
