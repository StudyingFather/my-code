#include <cstdio>
#include <iostream>
using namespace std;
int p[10000005],sta[10000005],ls[10000005],rs[10000005],n;
long long ans1,ans2;
int read()
{
 int res=0;
 char c=getchar();
 while(c<'0'||c>'9')
  c=getchar();
 while(c>='0'&&c<='9')
 {
  res=res*10+c-'0';
  c=getchar();
 }
 return res;
}
void build()
{
 int top=0,cur=0;
 for(int i=1;i<=n;i++)
 {
  cur=top;
  while(cur&&p[sta[cur]]>p[i])
   cur--;
  if(cur)
   rs[sta[cur]]=i;
  if(cur<top)
   ls[i]=sta[cur+1];
  sta[++cur]=i;
  top=cur;
 }
}
int main()
{
 n=read();
 for(int i=1;i<=n;i++)
  p[i]=read();
 build();
 for(long long i=1;i<=n;i++)
  ans1^=i*(ls[i]+1),ans2^=i*(rs[i]+1);
 cout<<ans1<<' '<<ans2<<endl;
 return 0;
}