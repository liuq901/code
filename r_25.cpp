#include <cstdio>
#include <cstdlib>
int main()
{
   long x1,y1,x2,y2,n,i,j,sum;
   long a[10001];
   scanf("%ld",&n);
   for (i=1;i<=n;i++)
      scanf("%ld",&a[i]);
   sum=0;
   j=n;
   while (j!=2)
   {
      x1=y1=2147483647;
      for (i=1;i<=j;i++)
         if (a[i]<x1)
            y1=x1,y2=x2,x1=a[i],x2=i;
         else
            if (a[i]<y1)
               y1=a[i],y2=i;
      sum+=x1+y1;
      a[x2]=x1+y1;
      a[y2]=a[j];
      a[j]=0;
      j--;
   }
   sum+=a[1]+a[2];
   printf("%d\n",sum);
   system("pause");
   return(0);
}
