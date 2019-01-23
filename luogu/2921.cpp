#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int nxt[100005],col[100005],dfn[100005],edfn[100005],minc[100005];
int n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&nxt[i]);
 for(int i=1;i<=n;i++)
  for(int j=i,cnt=0;;j=nxt[j],cnt++)
   if(!col[j])
   {
	col[j]=i;
	dfn[j]=cnt;
   }
   else if(col[j]==i)
   {
	minc[i]=cnt-dfn[j];
	edfn[i]=dfn[j];
	printf("%d\n",cnt);
	break;
   }
   else
   {
	minc[i]=minc[col[j]];
	edfn[i]=cnt+max(0,edfn[col[j]]-dfn[j]);
	printf("%d\n",minc[i]+edfn[i]);
	break;
   }
 return 0;
}