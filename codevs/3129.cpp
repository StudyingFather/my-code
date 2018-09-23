#include <cstdio>
using namespace std;
int num,n,min=2147483647,max=-2147483648;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&num);
  if(num>max)max=num;
  if(num<min)min=num;
 }
 for(int i=min;i<=max;i++)
  printf("%d ",i);
 return 0;
}
