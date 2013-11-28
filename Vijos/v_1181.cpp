#include <cstdio>
#include <cstdlib>
const int a[9]={0,9,90,900,9000,90000,900000,9000000,90000000};
int main()
{
   int b[26];
   int i,k,n,x,y;
   scanf("%d",&n);
   i=0;
   while (1)
   {
      i++;
      if (n>a[i]*i)
         n-=a[i]*i;
      else
         break;
   }
   k=i;
   x=1;
   for (i=1;i<=k-1;i++)
      x*=10;
   x+=n/k;
   y=n%k;
   if (y==0)
      printf("%d\n",(x-1)%10);
   else
   {
      i=0;
      while (x!=0)
      {
         i++;
         b[i]=x%10;
         x/=10;
      }
      k=i;
      printf("%d\n",b[k-y+1]);
   }
   system("pause");
   return(0);
}
