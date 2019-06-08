#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int r,c;
}a[1005];
int main()
{
 int n;
 scanf("%d",&n);
 a[1].r=a[1].c=1;
 int mid=n/2+1;
 printf("%d\n",mid);
 for(int i=1;i<=mid;i++)
  printf("1 %d\n",i);
 for(int i=mid+1;i<=n;i++)
  printf("%d %d\n",i-mid+1,mid);
 return 0;
}