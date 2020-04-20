#include <iostream>
using namespace std;
char s[100005];
int res[100005];
int main()
{
 ios::sync_with_stdio(false);
 int a,b;
 cin>>a>>b;
 cin>>(s+1);
 if(a==10&&(b==1||s[1]=='1'))
 {
  cout<<-1<<endl;
  return 0;
 }
 else
 {
  bool flag=true;
  int num=0;
  for(int i=1;i<=b;i++)
  {
   if(s[i]=='1')
   {
    if(i==1)res[i]=(a==10?1:a);
    else res[i]=(a-num*10%a)%a;
    flag=true;
    num=0;
   }
   else
   {
    if(flag||num*10%a==0)
    {
     res[i]=num=1;
     flag=false;
    }
    else num=num*10%a;
   }
  }
 }
 for(int i=1;i<=b;i++)
  cout<<res[i];
 cout<<endl;
 return 0;
}