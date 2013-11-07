#include <cstdio>
#include <cstdlib>
int main()
{
   int a[260];
   int i,j,k,n,m;
   scanf("%d",&n);
   scanf("%d",&m);
   for (i=1;i<=n;i++)
      a[i]=i;
   k=1;
   for (i=1;i<=m-1;i++)
   {
      k+=i*i*i%5+1;
      if (k>n)
      k=i*i*i%5+2;
      for (j=k;j<=n;j++)
         a[j]=a[j+1];
      n--;
   }
   k+=i*i*i%5+1;
   if (k>n)
      k=i*i*i%5+2;
   printf("%d\n",a[k]);
   system("pause");
   return(0);
}
