#include <cstdio>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
map<int,int> diff;
int n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  diff[l]++;
  diff[r+1]--;
 }
 int cnt=0;
 for(map<int,int>::iterator it=diff.begin();it!=diff.end();it++)
 {
  cnt+=it->second;
  if(cnt>2)
  {
   puts("NO");
   return 0;
  }
 }
 puts("YES");
 return 0;
}
