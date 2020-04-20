#include <iostream>
#include <bitset>
using namespace std;
char s[505][505],t[5005];
bitset<505*505> ma,f,w,e;
int main()
{
 int r,c,m;
 cin>>r>>c>>m;
 for(int i=1;i<=r;i++)
  cin>>(s[i]+1);
 cin>>(t+1);
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
  {
   if(s[i][j]=='.')ma[(i-1)*c+j]=1;
   if(j!=1)e[(i-1)*c+j]=1;
   if(j!=c)w[(i-1)*c+j]=1;
  }
 f=ma;
 for(int i=1;i<=m;i++)
 {
  if(t[i]=='N')f=(f>>c)&ma;
  else if(t[i]=='S')f=(f<<c)&ma;
  else if(t[i]=='W')f=(f>>1)&w&ma;
  else if(t[i]=='E')f=(f<<1)&e&ma;
  else f=((f>>c)|(f<<c)|(f>>1&w)|(f<<1&e))&ma;
 }
 cout<<f.count()<<endl;
 return 0;
}