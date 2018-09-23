#include <stdio.h>
int daynum[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int is_huiwen(int date)
{
 int a[10];
 for(int i=8;i>=1;i--)
 {
  a[i]=date%10;
  date/=10;
 }
 for(int i=1,j=8;i<=j;i++,j--)
  if(a[i]!=a[j])return 0;
 return 1;
}
int is_run(int year)
{
 return (year%4==0&&year%100!=0)||(year%400==0);
}
int edit(int date)
{
 int year,month,day,flag;
 year=date/10000;
 month=date%10000/100;
 day=date%100;
 flag=is_run(year);
 if(flag)daynum[2]=29;
 else daynum[2]=28;
 day++;
 if(day>daynum[month])
 {
  month++;
  day=1;
  if(month>12)
  {
   year++;
   month=1;
  }
 }
 return year*10000+month*100+day;
}
int main()
{
 int date1,date2,ans=0;
 scanf("%d%d",&date1,&date2);
 int date3=date1;
 while(date3<=date2)
 {
  if(is_huiwen(date3))ans++;
  date3=edit(date3);
 }
 printf("%d",ans);
 return 0;
}
