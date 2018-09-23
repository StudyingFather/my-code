#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int a[15];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>s;
  if(s=="purple")a[1]++;
  if(s=="green")a[2]++;
  if(s=="blue")a[3]++;
  if(s=="orange")a[4]++;
  if(s=="red")a[5]++;
  if(s=="yellow")a[6]++;
 }
 cout<<6-n<<endl;
 for(int i=1;i<=6-n;i++)
 {
  if(!a[1])cout<<"Power",a[1]++;
  else if(!a[2])cout<<"Time",a[2]++; 
  else if(!a[3])cout<<"Space",a[3]++;
  else if(!a[4])cout<<"Soul",a[4]++;
  else if(!a[5])cout<<"Reality",a[5]++;
  else if(!a[6])cout<<"Mind",a[6]++;
  puts("");
 }
 return 0;
}
