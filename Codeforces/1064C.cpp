#include <cstdio>
#include <algorithm>
using namespace std;
char s[100005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 sort(s,s+n);
 printf("%s",s);
 return 0;
}
