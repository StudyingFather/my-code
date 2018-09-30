#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int num,t;
}t1[100005],t2[100005];
int a[100005],n;
bool cmp(const node&a,const node&b)
{
 return a.t>b.t;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=100000;i++)
  t1[i].num=t2[i].num=i;
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(i%2)t1[a[i]].t++;
  else t2[a[i]].t++;
 }
 sort(t1+1,t1+100001,cmp);
 sort(t2+1,t2+100001,cmp);
 if(t1[1].num!=t2[1].num)printf("%d",(n/2-t1[1].t)+(n/2-t2[1].t));
 else printf("%d",min((n/2-t1[1].t)+(n/2-t2[2].t),(n/2-t1[2].t)+(n/2-t2[1].t)));
 return 0;
}