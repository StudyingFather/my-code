#include <cstdio>
#include <algorithm>
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
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int o,x;
  scanf("%d",&o);
  if(o==1)
  {
   scanf("%d",&x);
   insert(x);
  }
  if(o==2)printf("%d\n",top());
  if(o==3)pop();
 }
 return 0;
}
