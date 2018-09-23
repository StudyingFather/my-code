#include <stdio.h>
int t[35][35];
char s[100];
int maxt,ansi,ansj;
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 for(int i=1;i<n;i++)
  t[s[i-1]-'A'][s[i]-'A']++;
 for(int i=0;i<26;i++)
  for(int j=0;j<26;j++)
   if(t[i][j]>maxt)
   {
   	ansi=i;
   	ansj=j;
   	maxt=t[i][j];
   }
 printf("%c%c",ansi+'A',ansj+'A');
 return 0;
}
