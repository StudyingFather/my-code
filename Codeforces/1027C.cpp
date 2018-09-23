#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

template<class T>void read(T &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
}

int to[10005];
int main()
{
 //ios::sync_with_stdio(false);
 int t;
 read(t);
 while(t--)
 {
  memset(to,0,sizeof(to));
  int n,mx=-1,mn=100000;
  int ff=0;
  read(n);
  for(int i=1;i<=n;i++)
  {
   int num;
   read(num);
   to[num]++;
   if(to[num]>=4)
   {
   	//cout<<num <<' '<<num<<' '<<num<<' '<<num<<endl;
   	printf("%d %d %d %d\n",num,num,num,num);
	ff=1;
	break;
   }
   if(num>mx)mx=num;
   if(num<mn)mn=num;
  }
  if(ff)continue;
  long long x=-1,y=-1,last=-1;
  for(int i=mn;i<=mx;i++)
   if(to[i]>=2)
   {
   	if(last==-1)
   	{
   	 last=x=i;
   	 continue;
   	}
   	else if(y==-1)
   	{
   	 last=y=i;
   	 continue;
   	}
   	else if((x*x+y*y)*last*i>(last*last+i*i)*x*y)
   	 x=last,y=i;
	last=i;
   }
  printf("%d %d %d %d\n",(int)x,(int)x,(int)y,(int)y);
 }
 return 0;
}
