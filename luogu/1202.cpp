#include <stdio.h>
const int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a[15],n;
bool is_run(int y)
{
 if(y%4==0)
 {
  if(y%100==0)return y%400==0?true:false;
  else return true;
 }
 return false;
}
int main()
{
 scanf("%d",&n);
 int y=1900,m=1,d=1,cur=0;
 while(y<1900+n)
 {
  d++,cur++,cur%=7;
  if(d>day[m]+(m==2&&is_run(y)?1:0))d=1,m++;
  if(m>12)m=1,y++;
  if(d==13)a[cur+1]++;
 }
 printf("%d %d ",a[6],a[7]);
 for(int i=1;i<=5;i++)
  printf("%d ",a[i]);
 return 0;
}
