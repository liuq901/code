#include <cstdio>
#include <cstdlib>
int main()
{
   int k,n,t,i,j,l,x,y;
   int a[1001];
   scanf("%d%d",&k,&n);
   a[1]=1;
   t=i=1;
   j=x=0;
   while (i!=n)
   {
      i++;
      j++;
      if (j==t)
      {
         x++;
         y=i;
         a[i]=1;
         for (l=1;l<=x;l++)
            a[i]*=k;
         j=0;
         t*=2;
      }
      else
         a[i]=a[y]+a[i-y];
   }
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
