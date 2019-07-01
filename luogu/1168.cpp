#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int> > q2;
int main()
{
 int n;
 scanf("%d",&n);
 int num;
 scanf("%d",&num);
 printf("%d\n",num);
 q1.push(num);
 for(int i=2;i<=n;i++)
 {
  scanf("%d",&num);
  if(num>q1.top())q2.push(num);
  else q1.push(num);
  while(abs((int)q1.size()-(int)q2.size())>1)
   if(q1.size()>q2.size())
   {
    q2.push(q1.top());
    q1.pop();
   }
   else
   {
    q1.push(q2.top());
    q2.pop();
   }
  if(i%2)
  {
   if(q1.size()>q2.size())printf("%d\n",q1.top());
   else printf("%d\n",q2.top());
  }
 }
 return 0;
}