#include <cstdio>
#include <algorithm>
using namespace std;
int l,n,mint,maxt,x;
int main()
{
 scanf("%d%d",&l,&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&x);
  mint=max(mint,min(x,l+1-x));
  maxt=max(maxt,max(x,l+1-x));
 }
 printf("%d %d",mint,maxt);
 return 0;
}
