#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,x,flag;
   int a[10][10],b[10][10],c[10][10];
   while (1)
   {
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      memset(c,0,sizeof(c));
      flag=1;
      for (i=1;i<=9;i++)
      {
         for (j=1;j<=9;j++)
         {
            if (scanf("%d",&x)==EOF)
            {
               flag=0;
               break;
            }
            a[i][x]++;
            b[j][x]++;
            c[(i-1)/3*3+(j-1)/3+1][x]++;
         }
         if (!flag)
            break;
      }
      if (!flag)
         break;
      flag=1;
      for (i=1;i<=9;i++)
      {
         for (j=1;j<=9;j++)
            if (a[i][j]>1 || b[i][j]>1 || c[i][j]>1)
            {
               printf("no\n");
               flag=0;
               break;
            }
         if (!flag)
            break;
      }
      if (flag)
         printf("yes\n");
   }
   system("pause");
   return(0);
}
