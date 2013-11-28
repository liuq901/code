#include <cstdio>
#include <cstdlib>
int n,sum,ans[8000001][2];
int main()
{
   void count(int,int,int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int m;
      scanf("%d%d",&n,&m);
      sum=1;
      count(0,1,1,1);
      ans[1][0]=0,ans[1][1]=1;
      ans[++sum][0]=1,ans[sum][1]=1;
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         printf("%d/%d\n",ans[x][0],ans[x][1]);
      }
   }
   system("pause");
   return(0);
}
void count(int a,int b,int c,int d)
{
   if (b*2+d<=n)
      count(a,b,a+c,b+d);
   ans[++sum][0]=a+c,ans[sum][1]=b+d;
   if (b+2*d<=n)
      count(a+c,b+d,c,d);
}
