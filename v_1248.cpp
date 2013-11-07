#include <cstdio>
#include <cstdlib>
int main()
{
   int n,x1,x2,x3,x4,i,j,k,l;
   double s,ans;
   scanf("%d%d%d%d%d",&n,&x1,&x2,&x3,&x4);
   ans=20000000;
   for (i=0;i<=n;i++)
   {
      if (i>10)
          break;
      for (j=0;j<=n-i;j++)
      {
         if (j>10)
            break;
         for (k=0;k<=n-i-j;k++)
         {
            l=n-i-j-k;
            if (k>10)
               break;
            if (l>10)
               continue;
            s=(20-i*2)*x1+((100-7*j)*x2*2+(100-9*k)*x3)/(double)((10+l)*x4);
            if (s<ans)
               ans=s;
         }
      }
   }
   printf("%.3lf\n",ans);
   system("pause");
   return(0);
}
