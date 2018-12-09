#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
set<long long> s;
int main()
{
 int n;
 cin>>n;
 if(!n)
 {
  cout<<0<<endl;
  return 0;
 }
 s.insert(1);
 set<long long>::iterator it=s.begin();
 for(int i=1;i<n;i++)
 {
  s.insert((*it)*2),s.insert((*it)*3),s.insert((*it)*5),s.insert((*it)*7);
  it++;
 }
 cout<<*it<<endl;
 return 0;
}
