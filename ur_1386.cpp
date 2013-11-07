#include <cstdio>
#include <cstdlib>
bool ans[110][110];
int b[4010],a[5][110][110][2];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=4;i++)
      for (int j=1;j<=n;j++)
         for (int k=1;k<=m;k++)
            scanf("%d%d",&a[i][j][k][0],&a[i][j][k][1]);
   int T;
   scanf("%d",&T);
   for (int i=1;i<=T;i++)
      scanf("%d",&b[i]);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         int x=i,y=j;
         for (int k=1;k<=T;k++)
         {
            int x0=x,y0=y,op=b[k];
            x=a[op][x0][y0][0],y=a[op][x0][y0][1];
         }
         ans[x][y]=true;
      }
   int sum=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (ans[i][j])
            sum++;
   printf("%d\n",sum);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (ans[i][j])
            printf("%d %d\n",i,j);
   system("pause");
   return(0);
}
