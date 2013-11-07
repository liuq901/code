#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x0,y0,flag,t,s;
   int x[10001][2],y[10001][2];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
      if (x[i][0]>x[i][1])
         t=x[i][0],x[i][0]=x[i][1],x[i][1]=t;
      if (y[i][0]>y[i][1])
         t=y[i][0],y[i][0]=y[i][1],y[i][1]=t;
   }
   scanf("%d%d",&x0,&y0);
   flag=1;
   for (i=1;i<=n;i++)
   {
      if (x[i][0]==x[i][1] && x0==x[i][0] && y0>=y[i][0] && y0<=y[i][1])
      {
         flag=0;
         break;
      }
      if (y[i][0]==y[i][1] && y0==y[i][0] && x0>=x[i][0] && x0<=x[i][1])
      {
         flag=0;
         break;
      }
   }
   if (!flag)
      printf("BORDER\n");
   else
   {
      s=0;
      for (i=1;i<=n;i++)
      {
         if (y[i][0]==y[i][1])
            continue;
         if (x0<x[i][0] && y0>y[i][0] && y0<=y[i][1])
            s++;
      }
      if (s%2==0)
         printf("OUTSIDE\n");
      else
         printf("INSIDE\n");
   }
   system("pause");
   return(0);
}
