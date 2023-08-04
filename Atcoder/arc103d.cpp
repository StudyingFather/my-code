#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
 int x,y;
}p[1005];
const char s[]="LRDU";
char res[55];
vector<int> d;
int main()
{
 int n,op;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>p[i].x>>p[i].y;
  if(i==1)op=(p[i].x+p[i].y)&1;
  else if(op!=((p[i].x+p[i].y)&1))
  {
   cout<<-1<<endl;
   return 0;
  }
 }
 cout<<32-op<<endl;
 cout<<1<<' ';
 d.push_back(0),d.push_back(1);
 for(int i=op;i<=30;i++)
 {
  d.push_back(1<<i);
  cout<<(1<<i)<<' ';
 }
 cout<<endl;
 for(int i=1;i<=n;i++)
 {
  long long x=0,y=0,tx=p[i].x,ty=p[i].y;
  for(int j=32-op;j;j--)
  {
   if(abs(tx-x)>abs(ty-y))
   {
    if(tx-x>0)res[j]='R',x=x+d[j];
    else res[j]='L',x=x-d[j];
   }
   else
   {
    if(ty-y>0)res[j]='U',y=y+d[j];
    else res[j]='D',y=y-d[j];
   }
  }
  cout<<(res+1)<<endl; 
 }
 return 0;
}