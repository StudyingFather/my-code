#include <stdio.h>
#include <string.h>
char s[1000005],t[1000005];
int nxt[1000005];
void getnext()
{
 int len=strlen(t+1);
 nxt[1]=0;
 for(int i=2,j=0;i<=len;i++)
 {
  while(j&&t[i]!=t[j+1])
   j=nxt[j];
  if(t[i]==t[j+1])j++;
  nxt[i]=j;
 }
}
int main()
{
 scanf("%s",s+1);
 scanf("%s",t+1);
 getnext();
 int lens=strlen(s+1),lent=strlen(t+1);
 for(int i=1,j=0;i<=lens;i++)
 {
  while(j&&s[i]!=t[j+1])
   j=nxt[j];
  if(s[i]==t[j+1])j++;
  if(j==lent)
  {
   printf("%d\n",i-lent+1);
   j=nxt[j];
  }
 }
 for(int i=1;i<=lent;i++)
  printf("%d ",nxt[i]);
 return 0;
}