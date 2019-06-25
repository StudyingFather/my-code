#include <cstdio>
#include <algorithm>
using namespace std;
char s[100005];
int main()
{
 int n,cnts=0,ans=0,res=0,back=0;
 bool flag=true;
 scanf("%d",&n);
 scanf("%s",s);
 for(int i=0;i<n;i++)
  if(s[i]=='G')cnts++,res++;
  else if(s[i]=='S')
  {
   if(i==0||s[i-1]=='S')
   {
    ans=max(res,ans);
    res=0;
    flag=true;
   }
   else if(!flag)
   {
    ans=max(res,ans);
    res=0;
    i=back;
    flag=true;
   }
   else back=i,res++,flag=false;
  }
 if(flag==true)res++;
 ans=max(res,ans);
 printf("%d\n",min(ans,cnts));
 return 0;
}
