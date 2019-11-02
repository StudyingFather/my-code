/*
 Name: luogu P5594
 Author: StudyingFather
 Date: 2019/10/20 14:08
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
vector<set<int> > v;
set<int> s;
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=0;i<=k;i++)
  v.push_back(s);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   int x;
   scanf("%d",&x);
   v[x].insert(j);
  }
 for(int i=1;i<=k;i++)
  printf("%d ",v[i].size());
 return 0;
}