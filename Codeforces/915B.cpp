#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n,pos,l,r;
 scanf("%d%d%d%d",&n,&pos,&l,&r);
 if(l==1&&r==n)
 {
  printf("0");
  return 0;
 }
 else if(pos>=l&&pos<=r)
 {
  if(l==1)
  {
   printf("%d",r-pos+1);
   return 0;
  }
  else if(r==n)
  {
   printf("%d",pos-l+1);
   return 0;
  }
  else printf("%d",min(pos-l+r-l,r-pos+r-l)+2);
 }
 else
 {
  if(pos<l)
  {
   if(r==n)printf("%d",l-pos+1);
   else printf("%d",r-pos+2);
  }
  else
  {
   if(l==1)printf("%d",pos-r+1);
   else printf("%d",pos-l+2);
  }
 }
 return 0;
}
