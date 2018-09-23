#include <stdio.h>
#include <string.h>
int f[305][305],ino[305],s[305],root[305][305];
int calc(int l,int r)
{
 if(l>r)return 1;//����
 else if(~f[l][r])return f[l][r];//���仯
 else if(l==r)return s[l];//Ҷ�ڵ�
 int ans=0;
 for(int i=l;i<=r;i++)//ö�ٸ��ڵ� 
 {
  int x=calc(l,i-1)*calc(i+1,r)+s[i];
  if(x>ans)
  {
   root[l][r]=i;
   ans=x;
  }
 }
 return f[l][r]=ans;
}
void print_tree(int l,int r)
{
 printf("%d ",root[l][r]);
 if(l<=root[l][r]-1)print_tree(l,root[l][r]-1);//��������� 
 if(root[l][r]+1<=r)print_tree(root[l][r]+1,r);//��������� 
 return;
}
int main()
{
 int n;
 memset(f,-1,sizeof(f));
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&s[i]);
 for(int i=1;i<=n;i++)
  root[i][i]=i;
 printf("%d\n",calc(1,n));
 print_tree(1,n);
 return 0;
}
