#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
queue<int> q;
stack<int> s;
priority_queue<int> maxh;
priority_queue<int,vector<int>,greater<int> > minh;
bool a[5]={0,1,1,1,1};
int main()
{
 int n;
 cin>>n;
 while(n--)
 {
  int op,v;
  cin>>op>>v;
  if(op==1)
  {
   q.push(v);
   s.push(v);
   maxh.push(v);
   minh.push(v);
  }
  else
  {
   if(q.empty())a[1]=false;
   if(s.empty())a[2]=false;
   if(maxh.empty())a[3]=false;
   if(minh.empty())a[4]=false;
   if(a[1]&&q.front()!=v)a[1]=false;
   if(a[2]&&s.top()!=v)a[2]=false;
   if(a[3]&&maxh.top()!=v)a[3]=false;
   if(a[4]&&minh.top()!=v)a[4]=false;
   if(a[1])q.pop();
   if(a[2])s.pop();
   if(a[3])maxh.pop();
   if(a[4])minh.pop();
  }
 }
 for(int i=1;i<=4;i++)
  cout<<(a[i]?"Yes":"No")<<endl;
 return 0;
}