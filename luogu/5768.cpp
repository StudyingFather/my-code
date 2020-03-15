#include <cstdio>
#include <stack>
using namespace std;
typedef unsigned ui;
struct trie
{
 struct node
 {
  int son[2],ed;
 }p[10000005];
 int tot=1,id=0;
 void insert(ui ip,int len)
 {
  int u=1;
  for(int i=31;32-i<=len;i--)
  {
   int v=(ip>>i)&1;
   if(p[u].son[v])u=p[u].son[v];
   else
   {
    p[u].son[v]=++tot;
    u=tot;
   }
  }
  p[u].ed=++id;
 }
 int query(ui ip,int t)
 {
  stack<int> s;
  int u=1,pos=31;
  while(1)
  {
   if(p[u].ed&&p[u].ed<=t)
   {
    int ed=p[u].ed;
    while(!s.empty()&&ed<s.top())
     s.pop();
    s.push(ed);
   }
   int v=(ip>>pos)&1;
   if(!p[u].son[v])break;
   else u=p[u].son[v];
   pos--;
  }
  return s.size();
 }
}tr;
char op[5];
ui getip()
{
 ui ip=0;
 int a,b,c,d;
 scanf("%d.%d.%d.%d/",&a,&b,&c,&d);
 ip=(ip<<8)+a,ip=(ip<<8)+b,ip=(ip<<8)+c,ip=(ip<<8)+d;
 return ip;
}
int main()
{
 int m;
 scanf("%d",&m);
 while(m--)
 {
  scanf("%s",op);
  if(op[0]=='A')
  {
   ui ip=getip();
   int len;
   scanf("%d",&len);
   tr.insert(ip,len);
  }
  else
  {
   ui ip=getip();
   int a,b;
   scanf("%d%d",&a,&b);
   printf("%d\n",tr.query(ip,b)-tr.query(ip,a-1));
  }
 }
 return 0;
}