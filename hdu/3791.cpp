#include <stdio.h>
#include <string.h>
int a[2005],b[2005];
void build(int* tree,int pos,int k)
{
 if(tree[pos]==-1)
 {
  tree[pos]=k;
  return;
 }
 if(k<tree[pos])build(tree,pos*2,k);
 else build(tree,pos*2+1,k);
}
char s1[15],s2[15];
int main()
{
 int n;
 while(~scanf("%d",&n)&&n)
 {
  memset(a,-1,sizeof(a));
  scanf("%s",s1);
  int len=strlen(s1);
  for(int i=0;i<len;i++)
   build(a,1,s1[i]-'0');
  for(int i=1;i<=n;i++)
  {
   memset(b,-1,sizeof(b));
   scanf("%s",s2);
   for(int i=0;i<len;i++)
    build(b,1,s2[i]-'0');
   int flag=1;
   for(int i=1;i<=1024;i++)
    if(a[i]!=b[i])
    {
     flag=0;
     break;
    }
   if(flag)puts("YES");
   else puts("NO");
  }
 }
 return 0;
}
