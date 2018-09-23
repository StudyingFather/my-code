#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int heap[1000005],cnt;
void up(int p)
{
 while(p>=1&&heap[p]<heap[p/2])
 {
  swap(heap[p],heap[p/2]);
  p/=2;
 }
}
void down(int p)
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
void insert(int x)
{
 heap[++cnt]=x;
 up(cnt);
}
int top()
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
 while(~scanf("%d",&n)&&n)
 {
  int ans=0;
  cnt=0;
  memset(heap,0,sizeof(heap));
  for(int i=1;i<=n;i++)
  {
   int a;
   scanf("%d",&a);
   insert(a);
  }
  while(cnt!=1)
  {
   int newa=0;
   ans+=top();
   newa+=top();
   pop();
   ans+=top();
   newa+=top();
   pop();
   insert(newa);
  }
  printf("%d\n",ans);
 }
 return 0;
}
