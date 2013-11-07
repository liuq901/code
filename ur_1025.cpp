#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,j,t,s;
   int a[110];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (a[i]>a[j])
            t=a[i],a[i]=a[j],a[j]=t;
   s=0;
   for (i=1;i<=n/2+1;i++)
      s+=a[i]/2+1;
   printf("%d\n",s);
   system("pause");
   return(0);
}
