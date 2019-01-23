#include <iostream>
#include <cstdio>
#include <cctype>
#define MOD 19260817
using namespace std;
long long read()
{
 long long ans=0;
 char ch=getchar();
 while(!isdigit(ch)&&ch!=EOF)
  ch=getchar();
 while(isdigit(ch))
 {
  ans=(ans*10+(ch-'0'))%MOD;
  ch=getchar();
 }
 return ans;
}
void exgcd(long long a,long long b,long long&x,long long &y)
{
 if(b==0)
 {
  x=1;
  y=0;
  return;
 }
 exgcd(b,a%b,x,y);
 long long t=x;
 x=y;
 y=t-a/b*y;
 return;
}
int main()
{
 long long a=read(),b=read(),x,y;
 if(b==0)
 {
  cout<<"Angry!"<<endl;
  return 0;
 }
 exgcd(b,MOD,x,y);
 cout<<a*(x+MOD)%MOD<<endl;
 return 0;
}