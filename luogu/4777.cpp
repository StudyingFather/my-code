#include <iostream>
using namespace std;
__int128 ex_gcd(__int128 a,__int128 b,__int128&x,__int128&y)
{
 if(!b)
 {
  x=1,y=0;
  return a;
 }
 __int128 res=ex_gcd(b,a%b,x,y),tmp=x;
 x=y;
 y=tmp-a/b*y;
 return res;
}
__int128 gcd(__int128 x,__int128 y)
{
 return y==0?x:gcd(y,x%y);
}
__int128 lcm(__int128 x,__int128 y)
{
 return x/gcd(x,y)*y;
}
int main()
{
 __int128 n,A,B;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  __int128 a,b;
  cin>>a>>b;
  if(i==1)A=a,B=b;
  else
  {
   __int128 x,y,c=b-B;
   __int128 g=ex_gcd(A,a,x,y);
   x=smul(x,c/g,a/g);
   if(x<0)x+=a/g;
   __int128 MOD=lcm(A,a);
   B=(A*x+B)%MOD;
   if(B<0)B+=MOD;
   A=MOD;
  }
 }
 cout<<B%A<<endl;
 return 0;
}