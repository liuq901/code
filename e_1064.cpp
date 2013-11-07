#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   int a[5001];
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=n-1;i++)
      for (int j=i+1;j<=n;j++)
         if (a[i]>a[j])
         {
            printf("%d %d\n",a[i],a[j]);
            int t;
            t=a[i],a[i]=a[j],a[j]=t;
         }
   for (int i=1;i<n;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
