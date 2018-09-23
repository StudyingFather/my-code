#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long heap[1000005],cnt,ans;
void up(long long p)
{
 while(p>=1&&heap[p]<heap[p/2])
 {
  swap(heap[p],heap[p/2]);
  p/=2;
 }
}
void down(long long p)
{
 int s=p*2;
 while(s<=cnt)
 {
  if(s<cnt&&heap[s]>heap[s+1])s++;
  if(heap[s]<heap[p])
  {
   swap(heap[s],heap[p]);
   p=s;
   s=p*2;
  }
  else break;
 }
}
void insert(long long x)
{
 heap[++cnt]=x;
 up(cnt);
}
long long top()
{
 return heap[1];
}
void pop()
{
 heap[1]=heap[cnt--];
 down(1);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  long long a;
  cin>>a;
  insert(a);
 }
 while(cnt!=1)
 {
  long long newa=0;
  ans+=top();
  newa+=top();
  pop();
  ans+=top();
  newa+=top();
  pop();
  insert(newa);
 }
 cout<<ans;
 return 0;
}
