#include <cstdio>
#include <cstdlib>
int main()
{
   int x,y,m,n,i,j,t;
   scanf("%d%d",&m,&n);
   x=1<<m;
   y=1<<n;
   for (i=0;i<=x-1;i++)
   {
      t=(i^i>>1)<<n;
      for (j=0;j<=y-1;j++)
      {
         printf("%d",t|j^j>>1);
         if (j==y-1)
            printf("\n");
         else
            printf(" ");
      }
   }
   system("pause");
   return(0);
}
