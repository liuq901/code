#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x;
   int a[2][10];
   n=0;
   for (i=8;i>=0;i--)
   {
      scanf("%d",&x);
      if (x!=0)
      {
         n++;
         a[0][n]=x;
         a[1][n]=i;
      }
   }
   if (n==0)
      printf("0");
   else
   {
      if (a[1][1]!=1 && a[1][1]!=0)
         if (a[0][1]==1)
            printf("x^%d",a[1][1]);
         else if (a[0][1]==-1)
            printf("-x^%d",a[1][1]);
         else
            printf("%dx^%d",a[0][1],a[1][1]);
      else if (a[1][1]==1)
      {
         if (a[0][1]==1)
            printf("x");
         else if (a[0][1]==-1)
            printf("-x");
         else
            printf("%dx",a[0][1]);
      }
      else
         printf("%d",a[0][1]);
   }
   for (i=2;i<=n;i++)
   {
      printf(" ");
      if (a[0][i]<0)
         printf("-");
      else
         printf("+");
      printf(" ");
      if (abs(a[0][i])!=1)
         printf("%d",abs(a[0][i]));
      if (a[1][i]!=1 && a[1][i]!=0)
         printf("x^%d",a[1][i]);
      else if (a[1][i]==1)
         printf("x");
      if (abs(a[0][i])==1 && a[1][i]==0)
         printf("1");
   }
   printf("\n");
   system("pause");
   return(0);
}
