#include <cstdio>
#include <cstdlib>
int a[1000]={0};
int main()
{
   void chen(int);
   int n,i,x;
   scanf("%d",&n);
   x=n%3;
   n=n/3;
   if (x==0)
      for (i=1;i<=n;i++)
         chen(3);
   if (x==2)
   {
      for (i=1;i<=n;i++)
         chen(3);
      chen(2);
   }
   if (x==1)
   {
     for (i=1;i<=n-1;i++)
        chen(3);
     if (n==0)
        chen(1);
     else
        chen(4);
   }
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
void chen(int n)
{
   int x,i;
   if (a[0]==0)
   {
      a[0]=1;
      a[1]=n;
      return;
   }
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*n+x;
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
