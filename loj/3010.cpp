// Problem : #3010. 「JOI 2019 Final」勇者比太郎
// Contest : LibreOJ
// URL : https://loj.ac/problem/3010
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
char s[3005][3005];
int a[3005][3005],b[3005][3005];
int main()
{
 ios::sync_with_stdio(false);
 int w,h;
 long long ans=0;
 cin>>w>>h;
 for(int x=1;x<=w;x++)
  cin>>(s[x]+1);
 for(int x=1;x<=w;x++)
  for(int y=h;y;y--)
   a[x][y]=a[x][y+1]+(s[x][y]=='O');
 for(int y=1;y<=h;y++)
  for(int x=w;x;x--)
    b[x][y]=b[x+1][y]+(s[x][y]=='I');
 for(int x=1;x<=w;x++)
  for(int y=1;y<=h;y++)
   if(s[x][y]=='J')ans+=a[x][y]*b[x][y];
 cout<<ans<<endl;
 return 0;
}