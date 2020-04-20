#include <cstdio>
#include <vector>
using namespace std;
int t[1000005],sum[1000005];
vector<int> e[1000005];
char readc()
{
 char ch=0;
 while(ch!='s'&&ch!='e')
  ch=getchar();
 return ch;
}
int readi()
{
 int res=0;
 char ch=0;
 while(ch<'0'||ch>'9')
  ch=getchar();
 while(ch>='0'&&ch<='9')
  res=res*10+ch-'0',ch=getchar();
 return res;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  char ch=readc();
  t[i]=(ch=='s'?1:-1);
  int p=readi();
  e[p].push_back(i);
 }
 for(int i=1;i<=1000000;i++)
  if(e[i].size())
  {
   int cnt=0;
   for(auto p:e[i])
    cnt+=t[p];
   if(cnt)continue;
   int siz=e[i].size(),p=0;
   while(p<siz)
   {
    int q=p;
    bool flag=true;
    cnt=0;
    while(1)
    {
     cnt+=t[e[i][q]],q=(q+1)%siz;
     if(cnt<0)
     {
      flag=false;
      break;
     }
     if(q==p)break;
    }
    if(!flag)p=q;
    else
    {
     while(1)
     {
      cnt+=t[e[i][q]];
      if(cnt==0)
      {
       int l=e[i][q]+1,r=e[i][(q+1)%siz];
       sum[l]++,sum[r+1]--;
       if(l>r)sum[1]++;
      }
      q=(q+1)%siz;
      if(p==q)break;
     }
     break;
    }
   }
  }
 int ans=1;
 for(int i=2;i<=n;i++)
 {
  sum[i]+=sum[i-1];
  if(sum[i]>sum[ans])ans=i;
 }
 printf("%d %d\n",ans,sum[ans]);
 return 0;
}