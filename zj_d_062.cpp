#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,x,y,z,t,p,sum;
   int b[100],a[100][100];
   for (i=1;i<=34;i++)
   {
      a[i][1]=a[i][i]=1;
      for (j=2;j<=i-1;j++)
         a[i][j]=a[i-1][j-1]+a[i-1][j];
   }
   for (i=1;i<=34;i++)
      b[i]=a[i][(i+1)/2];
   while (scanf("%d%d%d",&x,&y,&z)!=EOF)
   {
      if (x==1)
      {
         if (y==1)
            printf("1\n");
         else
            printf("3\n");
         continue;
      }
      sum=0;
      for (i=1;i<=34;i++)
         if (x==b[i])
            break;
      t=i;
      z=0;
      p=(t-y+2)/2-1;
      for (i=t-y+1;i<=t;i++)
      {
         z++;
         for (j=1;j<=z;j++)
            sum+=a[i][j+p];
      }
      printf("%d\n",sum);
   }
   system("pause");
   return(0);
}
