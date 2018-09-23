#include <stdio.h>
#include <string.h>
int tot,fir,la,lb;
char a[100001],b[10000001],c[10000001];
int check(int x)
{
 for(int i=0;i<la;i++)
  if(b[x+i]!=a[i])return 0;
 if(b[x+la]!=' ')return 0;
 return 1; 
}
int main()
{
 gets(a);
 gets(b);
 la=strlen(a);
 lb=strlen(b);
 for(int i=0;i<la;i++)
  if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
 for(int i=0;i<lb;i++)
  if(b[i]>='A'&&b[i]<='Z')b[i]+=32;
 c[0]=' ';
 strcat(c,b);
 strcat(c," ");
 strcpy(b,c);
 lb=strlen(b);
 for(int i=0;i<lb;i++)
  if(b[i]==' '&&b[i+1]!=' ')
   if(check(i+1))
   {
    tot++;
    if(!fir)fir=i+1;
   }
 if(!tot)printf("-1");
 else printf("%d %d",tot,fir-1);
 return 0;
}
