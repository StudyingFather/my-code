#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
 ios::sync_with_stdio(false);
 long long n,sum=0,mins=0;
 int m;
 cin>>n>>m;
 while(m--)
 {
  string s;
  long long k,segs=0,segm=0;
  cin>>s>>k;
  for(auto c:s)
  {
   segs+=(c=='M'?1:-1);
   segm=min(segm,segs);
  }
  mins=min(mins,sum+min((k-1)*segs,0ll)+segm);
  sum+=k*segs;
 }
 if(sum>0)cout<<-1<<endl;
 else cout<<max(sum-mins-1,0ll)<<endl;
 return 0;
}