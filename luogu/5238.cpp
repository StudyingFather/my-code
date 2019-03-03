#include <iostream>
#include <cstring>
using namespace std;
char s[200005],s1[200005],s2[200005];
long long l,r,t;
int check_num()
{
 int len=strlen(s);
 if(s[0]=='-'&&(len==1||s[1]=='0'))return 1;
 else if(s[0]=='0'&&len!=1)return 1;
 return 0;
}
int check_range()
{
 unsigned long long num=0;
 int op=1,len=strlen(s);
 if(s[0]=='-'&&len>20)return 2;
 if(s[0]!='-'&&len>19)return 2;
 if(s[0]=='-')op=-1;
 for(int i=(op==1?0:1);i<len;i++)
  num=num*10+(s[i]-'0');
 if(op==-1&&num>(1ull<<63))return 2;
 if(op==1&&num>(1ull<<63)-1)return 2;
 long long num1=(long long)num*op;
 if(num1<l||num1>r)return 2;
 return 0;
}
int main()
{
 cin>>l>>r>>t;
 while(t--)
 {
  cin>>s;
  int flag=0;
  flag=check_num();
  if(flag)
  {
   cout<<flag<<endl;
   continue;
  }
  flag=check_range();
  cout<<flag<<endl;
 }
 return 0;
}
