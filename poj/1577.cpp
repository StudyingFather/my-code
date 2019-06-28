#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
int p,num;
char s[101][101];
struct node
{
 char val;
 int l,r;
}tr[101];
void insert(int p,char c)
{
 if(c<tr[p].val)
 {
  if(!tr[p].l)
  {
   tr[num].val=c;
   tr[p].l=num++;
  }
  else insert(tr[p].l,c);
 }
 else
 {
  if(!tr[p].r)
  {
   tr[num].val=c;
   tr[p].r=num++;
  }
  else insert(tr[p].r,c);
 }
}
void print(int pos)
{
 printf("%c",tr[pos].val);
 if(tr[pos].l)print(tr[pos].l);
 if(tr[pos].r)print(tr[pos].r);
}
int main()
{
 while(~scanf("%s",s[0]))
 {
  memset(tr,0,sizeof(tr));
  p=0;
  num=0;
  while(s[p][0]>='A'&&s[p][0]<='Z')
   scanf("%s",s[++p]);
  for(int i=p-1;i>=0;i--)
   for(int j=0;j<strlen(s[i]);j++)
    insert(0,s[i][j]);
  print(0);
  if(s[p][0]=='$')break;
  else printf("\n");
 }
 return 0;
}
