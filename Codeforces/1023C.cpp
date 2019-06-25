#include <stdio.h>
char s[200005],res[200005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 scanf("%s",s);
 if(n==k)printf("%s",s);
 else
 {
  int cntl=0,cntr=0,tot=0;
  for(int i=0;i<n;i++)
   if(s[i]=='(')
   {
    if(cntl!=k/2)
    {
     cntl++;
     res[tot++]='(';
    }
   }
   else
   {
    if(cntr!=k/2&&cntl>cntr)
    {
     cntr++;
     res[tot++]=')';
    }
   }
  printf("%s",res);
 }
 return 0;
}
