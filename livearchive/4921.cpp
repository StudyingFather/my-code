#include <iostream>
#include <cstring>
using namespace std;
char v[75];
int main()
{
 while(cin.getline(v+1,70))
 {
  if(v[1]=='#')return 0;
  int y=0,n=0,p=0,a=0,tot=strlen(v+1);
  for(int i=1;i<=tot;i++)
   if(v[i]=='Y')y++;
   else if(v[i]=='N')n++;
   else if(v[i]=='P')p++;
   else if(v[i]=='A')a++;
  if(a*2>=tot)cout<<"need quorum\n";
  else if(y>n)cout<<"yes\n";
  else if(y==n)cout<<"tie\n";
  else cout<<"no\n";
  memset(v,0,sizeof(v));
 }
 return 0;
}
