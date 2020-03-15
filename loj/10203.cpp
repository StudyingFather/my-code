#include <iostream>
#include <algorithm>
using namespace std;
const int p[]={0,2,3,5,7,11,13,17,19,23,29,31,37};
int t[15],n;
long long ans,maxd;
void dfs(long long num,int cur,int d)
{
 if(cur>=13)return;
 if(d>maxd)ans=num,maxd=d;
 else if(d==maxd)ans=min(ans,num);
 long long tmp=num;
 for(int i=0;i<=t[cur-1]&&tmp<=n;i++,tmp*=p[cur])
 {
  t[cur]=i;
  dfs(tmp,cur+1,d*(i+1));
 }
}
int main()
{
 cin>>n;
 t[0]=50;
 dfs(1,1,1);
 cout<<ans<<endl;
 return 0;
}