#include <stdio.h>
#include <string.h>
char k[105],m[1005];
int i,j,lm,lk;
int main()
{
 scanf("%s%s",k,m);
 lm=strlen(m);
 lk=strlen(k);
 for(i=0;i<lk;i++)
  if(k[i]>='A'&&k[i]<='Z')k[i]+=32;
 for(i=0;i<lm;i++)
 {
  for(j=0;j<lk;j++,i++)
   if(i>=lm)break;
   else if(m[i]>='A'&&m[i]<='Z'&&m[i]-k[j]+'a'<'A'||m[i]>='a'&&m[i]<='z'&&m[i]-k[j]+'a'<'a')
    m[i]=m[i]-k[j]+'a'+26;
   else m[i]-=k[j]-'a';
  i--;
 }
 puts(m);
 return 0;
}
