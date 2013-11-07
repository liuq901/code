#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[50010],b[50010];
int main()
{
   void insert(int,int),find(int,int);
   int i,m,k,x,y;
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d%d",&k,&x,&y);
      if (k==1)
         insert(x,y);
      else
         find(x,y);
   }
   system("pause");
   return(0);
}
void insert(int l,int r)
{
   int x;
   x=l;
   while (x<=n)
   {
      a[x]++;
      x+=x&-x;
   }
   x=r;
   while (x<=n)
   {
      b[x]++;
      x+=x&-x;
   }
}
void find(int l,int r)
{
   int x,ans1,ans2;
   ans1=0;
   x=r;
   while (x>0)
   {
      ans1+=a[x];
      x-=x&-x;
   }
   ans2=0;
   x=l-1;
   while (x>0)
   {
      ans2+=b[x];
      x-=x&-x;
   }
   printf("%d\n",ans1-ans2);
}
