#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d%*c",&t);
   while (t--)
   {
      int a[10];
      for (int i=1;i<=4;i++)
      {
         a[i]=0;
         for (int j=1;j<=8;j++)
         {
            char ch;
            scanf("%c",&ch);
            a[i]=a[i]*2+ch-'0';
         }
      }
      scanf("%*c");
      for (int i=1;i<4;i++)
         printf("%d.",a[i]);
      printf("%d\n",a[4]);
   }
   system("pause");
   return(0);
}
