#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int i,j,t,n,m,y,p,x;
   int a[1001],c[1001];
   double s;
   double b[1001];
   scanf("%d%d%d",&n,&m,&y);
   p=m;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      a[i]=p*x/y;
      b[i]=fabs((double)a[i]/p-(double)x/y);
      m-=a[i];
      c[i]=i;
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (b[i]<b[j])
         {
            s=b[i],b[i]=b[j],b[j]=s;
            t=a[i],a[i]=a[j],a[j]=t;
            t=c[i],c[i]=c[j],c[j]=t;
         }
   i=0;
   while (m!=0)
   {
      i++;
      a[i]++;
      m--;
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (c[i]>c[j])
         {
            t=a[i],a[i]=a[j],a[j]=t;
            t=c[i],c[i]=c[j],c[j]=t;
         }
   for (i=1;i<=n-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
