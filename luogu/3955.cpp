#include <cstdio>
#include <algorithm>
using namespace std;
const int mod[]={1,10,100,1000,10000,100000,1000000,10000000};
int n,q,b[1005];
int main()
{
 scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 sort(b+1,b+n+1);
 for(int i=1;i<=q;i++)
 {
  int a,num,flag=0;
  scanf("%d%d",&a,&num);
  for(int i=1;i<=n;i++)
   if(num%mod[a]==b[i]%mod[a])
   {
   	printf("%d\n",b[i]);
   	flag=1;
   	break;
   }
  if(!flag)printf("-1\n");
 }
 return 0;
}
