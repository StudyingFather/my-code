#include <stdio.h>
#include <string.h>
int trie[3000005][30],tot=1;
void insert(char* str)
{
 int len=strlen(str),p=1;
 for(int i=0;i<len;i++)
 {
  int c=str[i]-'a';
  if(trie[p][c]==0)trie[p][c]=++tot;
  p=trie[p][c];
 }
}
int search(char* str)
{
 int len=strlen(str),p=1;
 for(int i=0;i<len;i++)
 {
  p=trie[p][str[i]-'a'];
  if(p==0)return 0;
 }
 return 1;
}
char s[15];
int main()
{
 int n,m;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  memset(s,0,sizeof(s));
  scanf("%s",s);
  insert(s);
 }
 scanf("%d",&m);
 for(int i=1;i<=m;i++)
 {
  memset(s,0,sizeof(s));
  scanf("%s",s);
  int flag=search(s);
  if(flag)puts("YES");
  else puts("NO");
 }
 return 0;
}
