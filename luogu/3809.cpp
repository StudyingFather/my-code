#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000005];
int sa[1000005],rak[1000005],tp[1000005],t[1000005],n,S=127;
void radix_sort()
{
 for(int i=0;i<=S;i++)
  t[i]=0;
 for(int i=1;i<=n;i++)
  t[rak[i]]++;
 for(int i=1;i<=S;i++)
  t[i]+=t[i-1];
 for(int i=n;i;i--)
  sa[t[rak[tp[i]]]--]=tp[i];
}
int main()
{
 scanf("%s",s+1);
 n=strlen(s+1);
 for(int i=1;i<=n;i++)
  rak[i]=s[i],tp[i]=i;
 radix_sort();
 for(int w=1,p=0;p<n;w<<=1,S=p)
 {
  p=0;
  for(int i=1;i<=w;i++)
   tp[++p]=n-w+i;
  for(int i=1;i<=n;i++)
   if(sa[i]>w)tp[++p]=sa[i]-w;
  radix_sort();
  swap(tp,rak);
  rak[sa[1]]=p=1;
  for(int i=2;i<=n;i++)
   if(tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w])rak[sa[i]]=p;
   else rak[sa[i]]=++p;
 }
 for(int i=1;i<=n;i++)
  printf("%d ",sa[i]);
 return 0;
}