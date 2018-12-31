#include <stdio.h>
#include <string.h>
char s1[55],s2[55];
int main()
{
 scanf("%s",s1+1);
 int len=strlen(s1+1),cnt=0;
 if(len%2)
 {
  s2[0]=s1[len/2+1],cnt++;
  for(int i=1;i<=len/2;i++)
   s2[cnt++]=s1[(len+1)/2+i],s2[cnt++]=s1[len/2-i+1];
 }
 else
  for(int i=1;i<=len/2;i++)
   s2[cnt++]=s1[len/2-i+1],s2[cnt++]=s1[(len+1)/2+i];
 puts(s2);
 return 0;
}
