#include <cstdio>
#include <cstdlib>
int main()
{
   int a[50],min[50][51][3],max[50][51][3];
   int n,m,i,j,k,tt,t,mm,m1,m2,temp;
   scanf("%d%d",&n,&m);
   for (i=0;i<=n-1;i++)
      scanf("%d",&a[i]);
   for (i=0;i<=n-1;i++)
   {
      temp=0;
      for (j=1;j<=n;j++)
      {
         temp+=a[(i+j-1)%n];
         if (temp>=0)
            tt=temp%10;
         else
            tt=(10-((-1)*temp)%10)%10;
         min[i][j][0]=tt;
         max[i][j][0]=tt;
         min[i][j][1]=tt;
         max[i][j][1]=tt;
      }
   }
   for (k=1;k<=m-1;k++)
   {
      for (j=k+1;j<=n;j++)
         for (i=0;i<=n-1;i++)
         {
            m1=2000000000;
            m2=-2000000000;
            for (t=k;t<=j-1;t++)
            {
               mm=min[i][t][1]*min[(i+t)%n][j-t][0];
               if (m1>mm)
                  m1=mm;
               mm=max[i][t][1]*max[(i+t)%n][j-t][0];
               if (m2<mm)
                  m2=mm;
            }
            min[i][j][2]=m1;
            max[i][j][2]=m2;
         }
      for (i=0;i<=n-1;i++)
         for (j=1;j<=n;j++)
         {
            min[i][j][1]=min[i][j][2];
            max[i][j][1]=max[i][j][2];
         }
   }
   m1=2000000000;
   m2=-2000000000;
   for (i=1;i<=n-1;i++)
   {
      if (m1>min[i][n][1])
         m1=min[i][n][1];
      if (m2<max[i][n][1])
         m2=max[i][n][1];
   }
   printf("%d\n",m1);
   printf("%d\n",m2);
   system("pause");
   return(0);
}
