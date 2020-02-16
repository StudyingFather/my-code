#include <iostream>
using namespace std;
bool is_run(int x)
{
 if(x%4)return false;
 if(x%100==0)
 {
  if(x%400==0)return true;
  else return false;
 }
 else return true;
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  int y1,m1,y2,m2,ans=0;
  cin>>m1>>y1>>m2>>y2;
  if(m1>=3)y1++;
  if(m2<=1)y2--;
  if(y1>y2)cout<<0<<endl;
  else
  {
   ans=(y2-y1)/400*101;
   y1%=400;
   y2%=400;
   if(y2<y1)y2+=400;
   for(int i=y1-1;i<y2;i++)
   {
    int c=i/100,y=i%100;
    int w=((y+y/4+c/4-2*c+39)%7+7)%7;
    if(w==6||(w==0&&!is_run(i+1)))
     ans++;
   }
   cout<<ans<<endl;
  }
 }
 return 0;
}