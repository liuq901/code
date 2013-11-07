#include <cstdio>
#include <cstdlib>
int a[1000000];
int main()
{
   int n,b,c,p,i,j,flag;
   scanf("%d%d",&n,&b);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   flag=0;
   for (i=1;i<=n-1;i++)
   {
      for (j=i+1;j<=n;j++)
         if (a[i]*i==a[j]*j)
         {
            c=(i+j)/2;
            flag=1;
            break;
         }
      if (flag)
         break;
   }
   p=0;
   if (b==1)
      for (i=n;i>=c;i--)
         p+=a[i];
   else
      for (i=1;i<=c;i++)
         p+=a[i];
   printf("%d %d\n",c,p);
   system("pause");
   return(0);
}
