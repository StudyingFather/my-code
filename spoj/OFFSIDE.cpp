#include <cstdio>
#include <algorithm>
using namespace std;
int b[15],c[15],a,d;
int main()
{
 while(~scanf("%d%d",&a,&d)&&a&&d)
 {
  for(int i=1;i<=a;i++)
   scanf("%d",&b[i]);
  for(int i=1;i<=d;i++)
   scanf("%d",&c[i]);
  sort(b+1,b+a+1);
  sort(c+1,c+d+1);
  printf("%s",b[1]<c[2]?"Y\n":"N\n");
 }
 return 0;
}
