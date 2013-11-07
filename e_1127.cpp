#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int x[102],y[102];
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      x[n+1]=x[1],y[n+1]=y[1];
      int sum=0;
      for (int i=1;i<=n;i++)
         sum+=x[i]*y[i+1]-x[i+1]*y[i];
      printf("%.1lf\n",sum/2.0);
   }
   system("pause");
   return(0);
}
