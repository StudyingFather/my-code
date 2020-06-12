#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int p1,p2,k;
  scanf("%d%d%d",&p1,&p2,&k);
  if(p1>p2)swap(p1,p2);
  int gnum=gcd(p1,p2);
  p1/=gnum,p2/=gnum;
  if(k==1)
  {
   puts("No");
   continue;
  }
  if(1ll*(k-1)*p1+1>=p2)
   puts("Yes");
  else
   puts("No");
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}