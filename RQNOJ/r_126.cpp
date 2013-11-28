#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,j,t,x,y,z;
   int a[1001],b[1001],c[1001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      a[i]=x+y+z;
      b[i]=x;
      c[i]=i;
   }
   for (i=1;i<=n-1;i++)
      for (j=i;j<=n;j++)
      {
         if (a[i]<a[j])
         {
            t=a[i],a[i]=a[j],a[j]=t;
            t=b[i],b[i]=b[j],b[j]=t;
            t=c[i],c[i]=c[j],c[j]=t;
         }
         if (a[i]==a[j] && b[i]<b[j])
         {
            t=a[i],a[i]=a[j],a[j]=t;
            t=b[i],b[i]=b[j],b[j]=t;
            t=c[i],c[i]=c[j],c[j]=t;
         }
         if (a[i]==a[j] && b[i]==b[j] && c[i]>c[j])
         {
            t=a[i],a[i]=a[j],a[j]=t;
            t=b[i],b[i]=b[j],b[j]=t;
            t=c[i],c[i]=c[j],c[j]=t;
         }
      }
   for (i=1;i<=5;i++)
      printf("%d %d\n",c[i],a[i]);
   system("pause");
   return(0);
}
