#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int a[201][201],f[201][201];
   int n,m,i,j,k,flag;
   scanf("%d%d",&n,&m);
   if (n==1)
   {
      printf("0\n");
      system("pause");
      return(0);
   }
   memset(f,26,sizeof(f));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
         if (a[i][j]<=(m+1)/2)
            f[i][j]=1;
         if (i==j)
            f[i][j]=0;
      }
   for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
            if (f[i][k]+f[k][j]<f[i][j])
               f[i][j]=f[i][k]+f[k][j];
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (f[i][j]>2)
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
   {
      printf("%d\n",(m+1)/2);
      for (i=1;i<=(m+1)/2-1;i++)
         printf("%d ",i);
      printf("%d\n",(m+1)/2);
   }
   else
   {
      printf("%d\n",m-(m+1)/2);
      for (i=(m+1)/2+1;i<=m-1;i++)
         printf("%d ",i);
      printf("%d\n",m);
   }
   system("pause");
   return(0);
}
