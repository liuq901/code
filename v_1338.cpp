#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,m,t;
   int a[500],b[500];
   scanf("%d%d%d",&n,&m,&t);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      b[a[i]]=i;
   }
   for (i=1;i<=n-1;i++)
      printf("%d ",a[(t-b[i]+b[m]+n-1)%n+1]);
   printf("%d\n",a[(t-b[n]+b[m]+n-1)%n+1]);
   system("pause");
   return(0);
}
