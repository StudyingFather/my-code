#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
class DigitStringDiv2
{
 public:
  int count(string S, int X)
  {
   int len=S.length(),ans=0;
   for(int i=0;i<len;i++)
   {
    if(S[i]=='0')continue;
    for(int j=i;j<len;j++)
    {
     int num=0;
     for(int k=i;k<=j;k++)
     {
      num*=10;
      num+=S[k]-'0';
     }
     if(num>X)ans++;
    }
   }
   return ans;
  }
};
