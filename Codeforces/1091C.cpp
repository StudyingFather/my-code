#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
long long n,n1,cur=2,cnt;
set<long long,greater<long long> > s;
long long calc(long long x)
{
 return (1+n1-x+1)*(n1/x)/2; 
}
int main()
{
 cin>>n;
 s.insert(1);
 n1=n;
 while(n!=1)
 {
  while(n%cur==0)
  {
   n/=cur;
   for(set<long long>::iterator it=s.begin();it!=s.end();it++)
    s.insert(cur*(*it));
  }
  cur++;
 }
 for(set<long long>::iterator it=s.begin();it!=s.end();it++)
  cout<<calc(*it)<<' ';
 return 0;
}
