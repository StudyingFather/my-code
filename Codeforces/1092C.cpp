#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct str
{
 char s[105];
 int len,id;
}a[205];
int n,res[205];
char s[105];
bool cmp(const str&a,const str&b)
{
 return a.len<b.len;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=2*n-2;i++)
 {
  scanf("%s",a[i].s);
  a[i].len=strlen(a[i].s);
  a[i].id=i;
 }
 sort(a+1,a+2*n-1,cmp);
 bool flag=true;
 s[0]=a[2*n-3].s[0];
 for(int i=1;i<=a[2*n-2].len;i++)
  s[i]=a[2*n-2].s[i-1];
 for(int i=1;i<=2*n-2;i+=2)
 {
  bool flag1=true;
  for(int j=0;j<a[i].len;j++)
   if(s[j]!=a[i].s[j])
   {
    flag1=false;
    break;
   }
  flag1=true;
  for(int j=0;j<a[i].len;j++)
   if(s[n-a[i].len+j]!=a[i+1].s[j])
   {
    flag1=false;
    break;
   }
  if(flag1)
  {
   res[a[i].id]=0;
   res[a[i+1].id]=1;
   continue;
  }
  flag1=true;
  for(int j=0;j<a[i].len;j++)
   if(s[j]!=a[i+1].s[j])
   {
    flag1=false;
    break;
   }
  for(int j=0;j<a[i].len;j++)
   if(s[n-a[i].len+j]!=a[i].s[j])
   {
    flag1=false;
    break;
   }
  if(flag1)
  {
   res[a[i+1].id]=0;
   res[a[i].id]=1;
   continue;
  }
  else
  {
   flag=false;
   break;
  }
 }
 if(flag)
 {
  for(int i=1;i<=2*n-2;i++)
   putchar(res[i]==0?'P':'S');
  return 0;
 }
 else
 {
  s[0]=a[2*n-2].s[0];
  for(int i=1;i<a[2*n-3].len;i++)
   s[i]=a[2*n-3].s[i-1];
 }
 for(int i=1;i<=2*n-2;i+=2)
 {
  bool flag1=true;
  for(int j=0;j<a[i].len;j++)
   if(s[j]!=a[i].s[j])
   {
    flag1=false;
    break;
   }
  flag1=true;
  for(int j=0;j<a[i].len;j++)
   if(s[n-a[i].len+j]!=a[i+1].s[j])
   {
    flag1=false;
    break;
   }
  if(flag1)
  {
   res[a[i].id]=0;
   res[a[i+1].id]=1;
   continue;
  }
  else
  {
   res[a[i+1].id]=0;
   res[a[i].id]=1;
   continue;
  }
 }
 for(int i=1;i<=2*n-2;i++)
  putchar(res[i]==0?'P':'S');
 return 0;
}
