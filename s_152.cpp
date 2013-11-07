#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,s,t;
   int a[10001];
   scanf("%d",&n);
   s=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      s+=a[i];
      a[i]*=100;
   }
   t=0;
   for (i=1;i<=n-1;i++)
   {
      printf("%d ",(a[i]+t)/s);
      t=a[i]+t-(a[i]+t)/s*s;
   }
   printf("%d\n",(a[i]+t)/s);
   system("pause");
   return(0);
}
