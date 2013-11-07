#include <cstdio>
#include <cstdlib>
double x[110],y[110];
int a[110],c[110];
int main()
{
   void init();
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      long long sum=0,tot=0;
      for (int i=1;i<=n;i++)
         sum+=a[i]*a[i];
      for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
            tot+=a[i]*a[j];
      static int id=0;
      printf("Case %d: %.2f\n",++id,sum*x[n]+tot*y[n]);
   }
   system("pause");
   return(0);
}
void init()
{
   x[1]=y[1]=0;
   for (int i=2;i<=100;i++)
   {
      c[i]=i*(i-1)>>1;
      x[i]=(c[i]*x[i-1]+i-1)/c[i];
      y[i]=(2*x[i-1]+(c[i]-1)*y[i-1]+2)/c[i];
   }
}
