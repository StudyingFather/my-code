#include <cstdio>
#include <vector>
using namespace std;
int n,x,y,z,w,x1,y1,z1,w1,x2,y2,z2,w2;
char s[2][5005];
vector<int> e[4];
bool calc()
{
 for(z1=0;z1<=z;z1++)
 {
  y2=z1+w1-w2;
  z2=z-z1;
  y1=y-y2;
  x1=(n>>1)-y1-z1-w1;
  x2=x-x1;
  if(x1>=0&&x2>=0&&y1>=0&&y2>=0&&z1>=0&&z2>=0&&w1>=0&&w2>=0)return true;
 }
 return false;
}
int main()
{
 scanf("%d",&n);
 scanf("%s",s[0]+1);
 scanf("%s",s[1]+1);
 for(int i=1;i<=n;i++)
 {
  int x=s[0][i]-'0',y=s[1][i]-'0';
  int k=(x<<1)|y;
  e[k].push_back(i);
 }
 x=e[0].size();
 y=e[1].size();
 z=e[2].size();
 w=e[3].size();
 for(w1=0;w1<=w;w1++)
 {
  w2=w-w1;
  if(calc())
  {
   for(int i=0;i<x1;i++)
    printf("%d ",e[0][i]);
   for(int i=0;i<y1;i++)
    printf("%d ",e[1][i]);
   for(int i=0;i<z1;i++)
    printf("%d ",e[2][i]);
   for(int i=0;i<w1;i++)
    printf("%d ", e[3][i]);
   return 0;
  }
 }
 puts("-1");
 return 0;
}