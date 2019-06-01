#include <cstdio>
#include <set>
using namespace std;
set<int> se;
int main()
{
 int n;
 scanf("%d",&n);
 se.insert(n);
 while(1)
 {
  n++;
  while(n%10==0)
   n/=10;
  if(se.count(n))break;
  se.insert(n);
 }
 printf("%d\n",se.size());
 return 0;
}