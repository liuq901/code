#include <cstdio>
#include <cstdlib>
int main()
{
   long a[10000],y,i=0,j,l,k,n,x=0;
   scanf("%ld%ld",&k,&n);
   while (1)
   {
      i++;
      a[i]=1;
      for (j=1;j<=x;j++)
        a[i]*=k;
      y=a[i];
      l=i;
      if (i==n)
         goto lq;
      for (j=1;j<l;j++)
      {
         i++;
         a[i]=a[j]+y;
         if (i==n)
            goto lq;
      }
      x++;
   }
lq:
   printf("%ld\n",a[n]);
   system("pause");
   return(0);
}
