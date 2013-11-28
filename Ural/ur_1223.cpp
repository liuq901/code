#include <cstdio>
#include <cstdlib>
int f[1001][11];
int main()
{
   void init();
   init();
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      if (n>10)
         n=10;
      printf("%d\n",f[m][n]);
   }
   system("pause");
   return(0);
}
void init()
{
   int min(int,int),max(int,int);
   for (int i=1;i<=1000;i++)
   {
      f[i][0]=0;
      f[i][1]=i;
   }
   for (int i=1;i<=10;i++)
   {
      f[0][i]=0;
      f[1][i]=1;
   }
   for (int j=2;j<=10;j++)
      for (int i=2;i<=1000;i++)
      {
         f[i][j]=1<<30;
         for (int k=1;k<=i;k++)
            f[i][j]=min(f[i][j],max(f[k-1][j-1],f[i-k][j])+1);
      }
}
int min(int x,int y)
{
   return(x<y?x:y);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
