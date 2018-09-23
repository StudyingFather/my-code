#include <stdio.h>
#include <string.h>
using namespace std;
int a[10000005],b[10000005],c[10000005],x=1;
int fa=1,fb=1,fc=1,ra=0,rb=0,rc=0,total=1;
int main()
{
 while(total<=1500)
 {
  if(total==1500)printf("The 1500'th ugly number is %d.\n",x);
  a[++ra]=2*x;
  b[++rb]=3*x;
  c[++rc]=5*x;
  if(a[fa]<b[fb]&&a[fa]<c[fc]) x=a[fa++];
  else if(b[fb]<a[fa]&&b[fb]<c[fc]) x=b[fb++];
  else if(c[fc]<a[fa]&&c[fc]<b[fb]) x=c[fc++];
  else
  {
   if(a[fa]==b[fb]&&a[fa]<c[fc])
   {
	x=a[fa++];
	fb++;
   }
   else if(a[fa]==c[fc]&&a[fa]<b[fb])
   {
	x=a[fa++];
	fc++;
   }
   else if(c[fc]==b[fb]&&c[fc]<a[fa])
   {
	x=c[fc++];
	fb++;
   }
   else if(c[fc]==b[fb]&&b[fb]==a[fa])
   {
	x=a[fa++];
	fb++;fc++;
   }
  }
  total++;
 }
 return 0;
}
