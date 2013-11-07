#include <cstdio>
#include <cstdlib>
int x[200010],y[200010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      int x0=x[n+1>>1],y0=y[n+1>>1],a,b;
      a=b=0;
      for (int i=1;i<=n;i++)
      {
         if (x[i]>x0 && y[i]>y0 || x[i]<x0 && y[i]<y0)
            a++;
         if (x[i]<x0 && y[i]>y0 || x[i]>x0 && y[i]<y0)
            b++;
      }
      printf("%d %d\n",a,b);
   }
   system("pause");
   return(0);
}
