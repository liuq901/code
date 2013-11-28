#include <cstdio>
#include <cstdlib>
int main()
{
   int n,t,x,i,j,k;
   int a[101][101];
   scanf("%d",&n);
   if (n==2)
   {
      printf("3 4\n");
      printf("5 2 3\n");
   }
   else
   {
      t=0;
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
         {
            t++;
            a[i][j]=t;
         }
      printf("%d",n);
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
            if (i+j>=n+3)
               printf(" %d",a[i][j]);
      printf("\n");
      if (n%2==0)
         t=n-1;
      else
         t=n;
      for (i=n+2;i>=3;i--)
      {
         t+=2;
         printf("%d",t);
         for (j=1;j<=n;j++)
            for (k=1;k<=n;k++)
               if (j+k==i)
                  printf(" %d",a[j][k]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
