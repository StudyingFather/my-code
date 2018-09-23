#include <stdio.h>
#include <string.h>
char s[6][105];
int main()
{
 char c;
 int n,j,l;
 scanf("%d",&n);
 getchar();
 for(int i=0;i<n;i++)
 {
  j=1;l=0;
  memset(s,0,sizeof(s));
  while((c=getchar())!='\n')
  {
   if(c=='<'||c=='>')
   {
    j++;
	l=0;
	continue;
   }
   s[j][l]=c;
   l++;
  }
  fgets(s[0],sizeof(s[0]),stdin);
  s[0][strlen(s[0])-1]='\0';
  s[0][strlen(s[0])-1]='\0';
  s[0][strlen(s[0])-1]='\0';
  s[0][strlen(s[0])-1]='\0';
  printf("%s%s%s%s%s\n",s[1],s[2],s[3],s[4],s[5]);
  printf("%s%s%s%s%s\n",s[0],s[4],s[3],s[2],s[5]);
 }
 return 0;
}
