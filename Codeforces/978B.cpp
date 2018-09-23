#include <stdio.h>
char s[105];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 int ans=0,numx=0;
 for(int i=0;i<n;i++)
 {
  if(s[i]=='x')numx++;
  else
  {
   if(numx>=3)ans+=numx-2;
   numx=0;
  }
 }
 if(numx>=3)ans+=numx-2;
 printf("%d",ans);
 return 0;
}
