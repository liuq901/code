#include <cstdio>
#include <cstdlib>
#include <cmath>
int a[21],ar[21];
int n,nn,k,kk,i,j,l,sum,s,x,y;
int main()
{
   int ss(int);
   scanf("%d%d",&n,&k);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=k;i++)
      ar[i]=i;
   s=x=0;
   for (i=n;i>=n-k+1;i--)
      x+=i;
   do
   {
      sum=0;
      for (i=1;i<=k;i++)
         sum+=a[ar[i]];
      if (ss(sum))
         s++;
      y=0;
      for (i=1;i<=k;i++)
         y+=ar[i];
      kk=ar[k];
      nn=n;
      i=0;
      do
      {
         if (kk<nn)
         {
            ar[k-i]++;
            l=k-i;
            while (l<k)
            {
               l++;
               ar[l]=ar[l-1]+1;
            }
            break;
         }
         else
         {
            i++;
            kk=ar[k-i];
            nn=n-i;
         }
      }while(x!=y);
   }while(x!=y);
   printf("%d\n",s);
   system("pause");
   return(0);
}
int ss(int n)
{
   int i;
   for (i=2;i<=sqrt(n);i++)
      if (n%i==0)
         return(0);
   return(1);
}
