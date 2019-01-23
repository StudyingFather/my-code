#include <cstdio>
#include <algorithm>
#define MAXC 1000000
using namespace std;
char s[15]="0123456789";
int main()
{
 int cnt=1;
 while(cnt<MAXC)
  next_permutation(s,s+10),cnt++;
 puts(s);
 return 0;
}
