#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      bool flag[41]={0};
      int n,m;
      scanf("%d%d",&n,&m);
      n*=2;
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         flag[x]=true;
      }
      int f[41][41]={0};
      f[0][0]=1;
      for (int i=1;i<=n;i++)
         for (int j=0;j<=i;j++)
         {
            if (j)
               f[i][j]+=f[i-1][j-1];
            if (!flag[i] && i-1>=j+1)
               f[i][j]+=f[i-1][j+1];
         }
      printf("%d\n",f[n][0]);
   }
   system("pause");
   return(0);
}
