#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstdio>
using namespace std;
map<string,int> tree;
string s;
int tot;
int main()
{
 //ios::sync_with_stdio(false);
 while(getline(cin,s))
 {
  tree[s]++;
  tot++;
 }
 for(map<string,int>::iterator it=tree.begin();it!=tree.end();it++)
 {
  cout<<it->first<<' ';
  printf("%.4lf\n",it->second*100.0/tot);
 }
 return 0;
}
