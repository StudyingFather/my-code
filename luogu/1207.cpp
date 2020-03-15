#include <cstdio>
#include <cstring>
int a[35],b,cnt;
void change(int x)
{
 cnt=0;
 while(x)
 {
  a[++cnt]=x%b;
  x/=b;
 }
}
bool is_pali(int x)
{
 change(x);
 for(int i=1;i<=cnt;i++)
  if(a[i]!=a[cnt-i+1])return false;
 return true;
}
bool check(int x)
{
 int cnt=0;
 for(b=2;b<=10;b++)
  if(is_pali(x))cnt++;
 return cnt>=2;
}
int main()
{
 int n,s;
 scanf("%d%d",&n,&s);
 for(int i=s+1;;i++)
 {
  if(check(i))
  {
   n--;
   printf("%d\n",i);
   if(!n)break;
  }
 }
 return 0;
}