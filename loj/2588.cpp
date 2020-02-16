#include <stdio.h>
#include <string.h> 
char zimu[35],passwd[105],word[105],want[105],use[35];
int main()
{
 int used=0;
 scanf("%s",passwd);
 scanf("%s",word);
 scanf("%s",want);
 int len1=strlen(word),len2=strlen(want);
 for(int i=0;i<len1;i++)
 {
  if(!zimu[passwd[i]-64])
  {
   if(use[word[i]-64])
   {
    printf("Failed");
    return 0;
   }
   zimu[passwd[i]-64]=word[i];
   use[word[i]-64]=1;
   used++;
  }
  else if(zimu[passwd[i]-64]!=word[i])
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
  want[i]=zimu[want[i]-64];
 printf("%s",want);
 return 0;
}