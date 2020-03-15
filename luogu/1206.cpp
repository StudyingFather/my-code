#include <cstdio>
#include <cstring>
int a[25],b,cnt;
void change(int x)
{
 cnt=0;
 while(x)
 {
  a[++cnt]=x%b;
  x/=b;
 }
}
bool check(int x)
{
 change(x);
 for(int i=1;i<=cnt;i++)
  if(a[i]!=a[cnt-i+1])return false;
 return true;
}
void print(int x)
{
 change(x);
 for(int i=cnt;i;i--)
 {
  if(a[i]<=9)putchar(a[i]+'0');
  else putchar(a[i]-10+'A');
 }
}
int main()
{
 scanf("%d",&b);
 for(int i=1;i<=300;i++)
  if(check(i*i))
  {
   print(i),putchar(' '),print(i*i);
   puts("");
  }
 return 0;
}