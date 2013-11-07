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
      int x[701],y[701];
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            int sum=2;
            for (int k=j+1;k<=n;k++)
            {
               int x1,y1,x2,y2;
               x1=x[j]-x[i];
               y1=y[j]-y[i];
               x2=x[k]-x[i];
               y2=y[k]-y[i];
               if (x1*y2==x2*y1)
                  sum++;
            }
            if (sum>ans)
               ans=sum;
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
