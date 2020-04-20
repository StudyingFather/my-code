extern "C" int Seniorious(int x);
extern "C" int Chtholly(int n,int c)
{
 int l=1,r=n;
 while(1)
 {
  int mid=(l+r)>>1;
  int res=Seniorious(mid);
  if(res==1)r=mid-1;
  else if(res==-1)l=mid+1;
  else return mid;
 }
}