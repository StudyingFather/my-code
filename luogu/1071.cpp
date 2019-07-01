#include <stdio.h>
#include <string.h> 
char zimu[35],password[105],word[105],wanted[105],use[35];
int main()
{
 int used=0;
 scanf("%s",password);
 scanf("%s",word);
 scanf("%s",wanted);
 int len1=strlen(word),len2=strlen(wanted);
 for(int i=0;i<len1;i++)
 {
  if(!zimu[password[i]-64])
  {
   if(use[word[i]])
   {
    printf("Failed");
    return 0;
   }
   zimu[password[i]-64]=word[i];
   use[word[i]]=1;
   used++;
  }
  else if(zimu[password[i]-64]!=word[i])
  {
   printf("Failed");
   return 0;
  }
 }
 if(used!=26)
 {
  printf("Failed");
  return 0;
 }
 for(int i=0;i<len2;i++)
  wanted[i]=zimu[wanted[i]-64];
 printf("%s",wanted);
 return 0;
}
