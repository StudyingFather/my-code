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
class PAndPuns
{
 public:
  string check(string text)
  {
   int a[2505];
   int len=text.length();
   for(int i=1;i<len;i++)
    a[i]=(text[i-1]-'a')*26+(text[i]-'a');
   for(int i=1;i<len;i++)
    for(int j=i+2;j<len;j++)
     if(a[i]==a[j])return "pun";
   return "not a pun";
  }
};