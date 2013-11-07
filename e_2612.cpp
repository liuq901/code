#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d%*c",&T);
   while (T--)
   {
      char ch;
      int n;
      scanf("%c%d%*c",&ch,&n);
      if (ch=='P')
      {
         for (int i=1;i<=n+2;i++)
            printf("0");
         printf("\n");
         for (int i=1;i<=n;i++)
         {
            printf("0");
            for (int i=1;i<=n;i++)
               printf("1");
            printf("0\n");
         }
         for (int i=1;i<=n+2;i++)
            printf("0");
         printf("\n");
         for (int i=1;i<=n+1;i++)
         {
            printf("0");
            for (int j=1;j<=n+1;j++)
               printf("1");
            printf("\n");
         }
      }
      else
      {
         for (int i=1;i<=n+2;i++)
            printf("0");
         printf("\n");
         for (int i=1;i<=(n<<1)+1;i++)
         {
            printf("0");
            for (int j=1;j<=n+1;j++)
               printf("1");
            printf("\n");
         }
         for (int i=1;i<=n+2;i++)
            printf("0");
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
