#include <cstdio>
#include <algorithm>
using namespace std;
char c;
int a[10000][2],b=0,d=0,i,l=0,p=0,w=0;
int main()
{
 while(1)
 {
  scanf("%c",&c);
  if(c=='E')break;
  if(c=='W')
  {
   w++;
   b++;
  }
  else if(c=='L')
  {
   l++;
   d++;
  }
  if((w>=11||l>=11)&&abs(w-l)>=2)
  {
   printf("%d:%d\n",w,l);
   w=0;
   l=0;
  }
  if((b>=21||d>=21)&&abs(b-d)>=2)
  {
   a[++p][0]=b;
   a[p][1]=d;
   b=0;
   d=0;
  }
 }
 printf("%d:%d\n\n",w,l);
 for(i=1;i<=p;i++)
  printf("%d:%d\n",a[i][0],a[i][1]);
 printf("%d:%d",b,d);
 return 0;
}
