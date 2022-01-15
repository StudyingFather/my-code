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
class NewBanknote
{
 public:
  vector<int> fewestPieces(int newBanknote, vector<int> amountsToPay)
  {
   int money[]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000,20000,50000};
   int t=amountsToPay.size();
   vector<int> res;
   for(int i=0;i<t;i++)
   {
    res.push_back(amountsToPay[i]);
    for(int j=0;j<=50000;j++)
    {
     long long num=(long long)amountsToPay[i]-newBanknote*j;
     if(num<0)break;
     int cnt=j;
     for(int k=14;k>=0;k--)
     {
      cnt+=num/money[k];
      num%=money[k];
     }
     res[i]=min(res[i],cnt);
    }
   }
   return res;
  }
};
