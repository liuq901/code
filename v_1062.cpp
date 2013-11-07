#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,i,j;
   int a[10000],b[10000];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
      for (j=a[i];j>=1;j--)
         if (!b[j])
         {
            b[j]=1;
            printf("%d",a[i]-j+1);
            if (i!=n)
               printf(" ");
            else
               printf("\n");
            break;
         }
   system("pause");
   return(0);
}
