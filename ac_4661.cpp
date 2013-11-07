#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const double eps=1e-10;
double a[60];
int b[60],c[60];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         double x;
         scanf("%lf",&x);
         if (fabs(x)<eps)
         {
            a[i]=b[i]=0;
            continue;
         }
         b[i]=0;
         while (x+eps<1)
         {
            b[i]--;
            x*=10.0;
         }
         a[i]=x;
      }
      int m;
      scanf("%d",&m);
      static int id=0;
      printf("Test Case #%d:\n",++id);
      for (int i=1;i<=m;i++)
      {
         double p=1;
         int pos=0;
         int k;
         scanf("%d",&k);
         memset(c,0,sizeof(c));
         for (int j=1;j<=k;j++)
         {
            int x;
            scanf("%d",&x);
            c[x]++;
            p*=a[x],pos+=b[x];
            if (p+eps>=10)
            {
               p/=10;
               pos++;
            }
         }
         for (int j=1;j<=k;j++)
         {
            p*=j;
            while (p+eps>=10)
            {
               p/=10;
               pos++;
            }
         }
         for (int j=1;j<=n;j++)
            for (int k=1;k<=c[j];k++)
            {
               p/=k;
               while (p+eps<1)
               {
                  p*=10;
                  pos--;
               }
            }
         printf("%.5f x 10^%d\n",p,pos);
      }
   }
   system("pause");
   return(0);
}
