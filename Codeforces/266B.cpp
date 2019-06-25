#include <cstdio>
#include <algorithm>
using namespace std;
char a[55];
int n,t;
int main()
{
 scanf("%d%d",&n,&t);
 scanf("%s",a);
 while(t--)
 {
  for(int i=0;i<=n;)
   if(a[i]=='B'&&a[i+1]=='G')
   {
    swap(a[i],a[i+1]);
    i+=2;
   }
   else i++;
 }
 printf("%s",a);
 return 0;
}
