#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,k,t;
   int a[4],b[4];
   for (i=1;i<=3;i++)
   {
      for (j=1;j<=3;j++)
         scanf("%d",&a[j]);
      for (j=1;j<=2;j++)
         for (k=j+1;k<=3;k++)
            if (a[j]>a[k])
               t=a[j],a[j]=a[k],a[k]=t;
      b[i]=a[2];
   }
   for (i=1;i<=2;i++)
      for (j=i+1;j<=3;j++)
         if (b[i]>b[j])
            t=b[i],b[i]=b[j],b[j]=t;
   printf("%d\n",b[2]);
   system("pause");
   return(0);
}
