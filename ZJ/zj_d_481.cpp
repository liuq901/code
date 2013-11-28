#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[110][110],b[110][110],c[110][110];
int main()
{
   int n1,m1,n2,m2;
   while (scanf("%d%d%d%d",&n1,&m1,&n2,&m2)==4)
   {
      if (m1!=n2)
      {
         printf("Error\n");
         continue;
      }
      for (int i=1;i<=n1;i++)
         for (int j=1;j<=m1;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n2;i++)
         for (int j=1;j<=m2;j++)
            scanf("%d",&b[i][j]);
      memset(c,0,sizeof(c));
      for (int i=1;i<=n1;i++)
         for (int j=1;j<=m2;j++)
            for (int k=1;k<=m1;k++)
               c[i][j]+=a[i][k]*b[k][j];
      for (int i=1;i<=n1;i++)
         for (int j=1;j<=m2;j++)
            printf("%d%c",c[i][j],j==m2?'\n':' ');
   }
   system("pause");
   return(0);
}
