#include "ramen.h"
void Ramen(int n)
{
 int maxa=0,mina=0;
 for(int i=1;i<n-1;i+=2)
  if(Compare(i,i+1)==1)
  {
   if(Compare(i,maxa)==1)maxa=i;
   if(Compare(i+1,mina)==-1)mina=i+1;
  }
  else
  {
   if(Compare(i+1,maxa)==1)maxa=i+1;
   if(Compare(i,mina)==-1)mina=i;
  }
 if(n%2==0)
 {
  if(Compare(n-1,maxa)==1)maxa=n-1;
  else if(Compare(n-1,mina)==-1)mina=n-1;
 }
 Answer(mina,maxa);
}