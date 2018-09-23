#include <iostream>
using namespace std;
int year,month,day;
int is_run()
{
 if(year%4==0&&(year%100!=0||year%400==0))return 29;
 return 28;
}
int is_bigmonth()
{
 if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)return 31;
 return 30;
}
int main()
{
 cin>>year>>month;
 if(month==2)day=is_run();
 else day=is_bigmonth();
 cout<<day;
 return 0;
}
