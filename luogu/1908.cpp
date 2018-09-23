#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct number
{
 int num,id;
}a[500005];
int n,c[500005];
long long ans;
int lowbit(int x)
{
 return x&(-x);
}
void add(int x,int k)//修改操作 
{
 for(int i=x;i<=n;i+=lowbit(i))
  c[i]+=k;
}
long long query(int x)//查询操作 
{
 long long sum=0;
 for(int i=x;i>0;i-=lowbit(i))
  sum+=c[i];
 return sum;
}
bool cmp(const number&x,const number&y)
{
 return x.num>y.num;
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].num;
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  add(a[i].id,1);
  ans+=query(a[i].id-1);
 }
 cout<<ans;
 return 0;
}
