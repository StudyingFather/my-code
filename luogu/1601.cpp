#include <stdio.h>
#include <string.h>
char a1[505],b1[505];
int a[505],b[505],c[505],lena,lenb,lenc,x;
int main()
{
 scanf("%s",a1);
 scanf("%s",b1);
 lena=strlen(a1);
 lenb=strlen(b1);
 for(int i=0;i<lena;i++)
  a[lena-i]=a1[i]-'0';
 for(int i=0;i<lenb;i++)
  b[lenb-i]=b1[i]-'0';
 lenc=1;
 while(lenc<=lena||lenc<=lenb)
 {
  c[lenc]=a[lenc]+b[lenc]+x;
  x=c[lenc]/10;
  c[lenc]%=10;
  lenc++;
 }
 c[lenc]=x;
 while(c[lenc]==0&&lenc>1)
  lenc--;
 for(int i=lenc;i>=1;i--)
  printf("%d",c[i]);
 return 0;
}
