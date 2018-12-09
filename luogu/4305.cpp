#include <cstdio>
#include <unordered_set>
#include <algorithm>
using namespace std;
unordered_set<int> s;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  s.clear();
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   int num;
   scanf("%d",&num);
   if(!s.count(num))printf("%d ",num),s.insert(num);
  }
  puts("");
 }
 return 0;
}
