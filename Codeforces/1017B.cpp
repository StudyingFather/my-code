#include <iostream>
using namespace std;
int n;
char s1[100005],s2[100005];
int main()
{
 cin>>n;
 cin>>s1;
 cin>>s2;
 long long num01=0,num00=0,num10=0,num11=0;
 for(int i=0;i<n;i++)
  if(s1[i]=='0'&&s2[i]=='1')num01++;
  else if(s1[i]=='0'&&s2[i]=='0')num00++;
  else if(s1[i]=='1'&&s2[i]=='0')num10++;
  else num11++;
 cout<<num01*num10+num00*num10+num00*num11;
 return 0;
}
