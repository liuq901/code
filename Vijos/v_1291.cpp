#include <cstdio>
#include <cstdlib>
int main()
{
   int m,n,i,j,p,s=0,min,a[2000],b[2000];
   scanf("%d%d",&n,&m);
   for (i=0;i<n;i++)
      scanf("%d",&a[i]);
   for (i=0;i<m;i++)
      scanf("%d",&b[i]);
   for (i=0;i<n;i++)
   {
      min=2147483647;
      p=-1;
      for (j=0;j<m;j++)
         if (b[j]>0 && a[i]>b[j] && a[i]-b[j]<min)
         {
            min=a[i]-b[j];
            p=j;
         }
      if (p!=-1)
      {
         s++;
         b[p]=0;
      }
   }
   printf("%d\n",m-s);
   system("pause");
   return(0);
}
