#include <cstdio>
#include <cstdlib>
int a[7000];
int main()
{
   void multi(int);
   int i,j;
   a[0]=a[1]=1;
   for (i=1;i<=100;i++)
      for (j=1;j<=i;j++)
         multi(101-i);
   for (i=a[0];i>=1;i--)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
void multi(int t)
{
   int x,i;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*t+x;
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
