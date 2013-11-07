#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int a[1001];
   int i,j,n;
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   a[0]=a[1]=1;
   for (i=2;i<=n;i++)
      if (i%2==0)
      {
         for (j=1;j<=i/2;j++)
            a[i]+=a[j];
         a[i]++;
      }
      else
         a[i]=a[i-1];
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
