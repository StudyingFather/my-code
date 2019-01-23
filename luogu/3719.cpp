#include <cstdio>
#include <algorithm>
using namespace std;
int calc()
{
 int cnt=0;
 char c;
 while(~(c=getchar()))
 {
  if(c=='a')cnt++;
  else if(c=='(')cnt+=calc();
  else if(c=='|')return max(cnt,calc());
  else if(c==')')return cnt;
 }
 return cnt;
} 
int main()
{
 printf("%d\n",calc());
 return 0;
}
