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
#include <cstring>
using namespace std;
class CinderellaGirls
{
 public:
  int count(vector<int>talent,vector<int>skill)
  {
   int a[55],ans=0;
   memset(a,0,sizeof(a));
   int n=skill.size();
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     if(talent[i]>talent[j]&&skill[i]>skill[j])a[j]=1;
   for(int i=0;i<n;i++)
    if(!a[i])ans++;
   return ans;
  }
};
