#include <cstdio>
#include <cstdlib>
int main()
{
   int j,i,n,a[200],x;
   scanf("%d",&n);
   a[0]=1;
   a[1]=2;
   for (i=1;i<=n;i++)
   {
      x=0;
      for (j=1;j<=a[0];j++)
      {
         a[j]=a[j]*2+x;
         x=a[j]/10;
         a[j]=a[j]%10;
      }
      if (x!=0)
      {
         a[0]++;
         a[a[0]]=x;
      }
   }
   a[1]-=2;
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
