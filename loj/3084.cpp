#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int gs[]={0,1,9,10,18,19,27,28,29,30,31,32,33,34};
const int shunzi[]={0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0};
long long c[5][5],re[35],dora[35],f[35][5][5][5][5][5],qd[35];
char s[5];
bool cmp(int a,int b)
{
 return a>b;
}
long long calc_gsws()
{
 long long ans=0;
 for(int i=1;i<=13;i++)
 {
  long long res=1;
  for(int j=1;j<=13;j++)
   if(i==j)
   {
    if(re[gs[j]]<2)res=0;
    else res*=c[re[gs[j]]][2]*(dora[gs[j]]?4:1);
   }
   else
   {
    if(re[gs[j]]<1)res=0;
    else res*=re[gs[j]]*(dora[gs[j]]?2:1);
   }
  ans=max(ans,res);
 }
 return ans*13;
}
long long calc_qd()
{
 for(int i=1;i<=34;i++)
  if(re[i]>=2)qd[i]=c[re[i]][2]*(dora[i]?4:1);
 sort(qd+1,qd+35,cmp);
 long long ans=1;
 for(int i=1;i<=7;i++)
  ans*=qd[i];
 return ans*7;
}
int main()
{
 int t;
 cin>>t;
 c[0][0]=1;
 for(int i=1;i<=4;i++)
 {
  c[i][0]=1;
  for(int j=1;j<=4;j++)
   c[i][j]=c[i-1][j]+c[i-1][j-1];
 }
 while(t--)
 {
  for(int i=1;i<=34;i++)
   re[i]=4;
  memset(dora,0,sizeof(dora));
  memset(f,0,sizeof(f));
  memset(qd,0,sizeof(qd));
  while(1)
  {
   cin>>s;
   int x=s[0]-'0';
   if(s[0]=='0')break;
   else if(s[0]=='E')re[28]--;
   else if(s[0]=='S')re[29]--;
   else if(s[0]=='W')re[30]--;
   else if(s[0]=='N')re[31]--;
   else if(s[0]=='Z')re[32]--;
   else if(s[0]=='B')re[33]--;
   else if(s[0]=='F')re[34]--;
   else if(s[1]=='m')re[x]--;
   else if(s[1]=='p')re[9+x]--;
   else re[18+x]--;
  }
  while(1)
  {
   cin>>s;
   int x=s[0]-'0';
   if(s[0]=='0')break;
   else if(s[0]=='E')dora[28]++;
   else if(s[0]=='S')dora[29]++;
   else if(s[0]=='W')dora[30]++;
   else if(s[0]=='N')dora[31]++;
   else if(s[0]=='Z')dora[32]++;
   else if(s[0]=='B')dora[33]++;
   else if(s[0]=='F')dora[34]++;
   else if(s[1]=='m')dora[x]++;
   else if(s[1]=='p')dora[9+x]++;
   else dora[18+x]++;
  }
  long long ans=max(calc_gsws(),calc_qd());
  f[1][0][0][0][0][0]=1;
  for(int i=1;i<=34;i++)
   for(int j=0;j<=4;j++)
    for(int k=0;k<=1;k++)
     for(int l=0;l<=4;l++)
      for(int m=0;m<=4;m++)
       for(int n=0;n<=4;n++)
       {
        long long cur=f[i][j][k][l][m][n];
        if(!cur)continue;
        if(i<34)f[i+1][j][k][m][n][0]=max(f[i+1][j][k][m][n][0],cur*(i>2?c[re[i-2]][l]:1)*(1<<(l*dora[i-2])));
        if(j<4&&re[i]-n>=3)f[i][j+1][k][l][m][n+3]=max(f[i][j+1][k][l][m][n+3],cur);
        if(j<4&&re[i]-n>=4)f[i][j+1][k][l][m][n+4]=max(f[i][j+1][k][l][m][n+4],cur);
        if(j<4&&shunzi[i]&&re[i]-n&&re[i-1]-m&&re[i-2]-l)f[i][j+1][k][l+1][m+1][n+1]=max(f[i][j+1][k][l+1][m+1][n+1],cur);
        if((!k)&&re[i]-n>=2)f[i][j][k+1][l][m][n+2]=max(f[i][j][k+1][l][m][n+2],cur);
        if(i==34&&j==4&&k==1)ans=max(ans,cur*c[re[i]][n]*c[re[i-1]][m]*c[re[i-2]][l]*(1<<(n*dora[i]))*(1<<(m*dora[i-1]))*(1<<(l*dora[i-2])));
       }
  cout<<ans<<endl;
 }
 return 0;
}