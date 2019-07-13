#include "interaction.h"
#include <vector>
using namespace std;
vector<int> res;
int main()
{
 int n=get_num();
 for(int i=0;i<n;i++)
 {
  int l=1,r=1000000;
  while(1)
  {
   int mid=(l+r)>>1;
   int flag=guess(i,mid);
   if(!flag)
   {
    res.push_back(mid);
    break;
   }
   else if(flag==1)r=mid-1;
   else l=mid+1;
  }
 }
 submit(res);
}