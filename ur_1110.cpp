#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,x,y,i,j,flag;
   scanf("%d%d%d",&n,&m,&y);
   flag=0;
   for (i=0;i<=m-1;i++)
   {
      x=1;
      for (j=1;j<=n;j++)
         x=x*i%m;
      if (x==y)
      {
         if (flag)
            printf(" ");
         printf("%d",i);
         flag=1;
      }
   }
   if (!flag)
      printf("-1");
   printf("\n");
   system("pause");
   return(0);
}
