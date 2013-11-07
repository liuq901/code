#include <cstdio>
#include <cstdlib>
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n,m,y;
   scanf("%d%d%d",&n,&m,&y);
   int x[1001];
   for (int i=1;i<=n;i++)
      scanf("%d",&x[i]);
   int m0=m/y*y;
   int a[1001];
   for (int i=1;i<=n;i++)
      a[i]=m0/y*x[i];
   int t=m;
   m-=m0;
   while (m!=0)
   {
      double max=-1e9;
      int k;
      for (int i=1;i<=n;i++)
         if (double(x[i])/y-double(a[i])/t>max)
         {
            max=double(x[i])/y-double(a[i])/t;
            k=i;
         }
      a[k]++;
      m0++;
      m--;
   }
   for (int i=1;i<n;i++)
      printf("%d ",a[i]);
   printf("%d\n\n",a[n]);
}
