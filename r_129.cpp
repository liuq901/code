#include <cstdio>
#include <cstdlib>
int a[10000];
int main()
{
   int muilt();
   int n,i;
   scanf("%d",&n);
   a[0]=1;
   a[1]=1;
   for (i=1;i<=n+1;i++)
      muilt();
   a[1]-=2;
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
int muilt()
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*2+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
