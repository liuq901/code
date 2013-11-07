#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,t,x,y,a[1001]={0};
   scanf("%d",&n);
   scanf("%d",&t);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&x,&y);
      for (j=t-y;j>=0;j--)
         if (a[j+y]<=a[j]+x)
            a[j+y]=a[j]+x;
   }
   printf("%d\n",a[t]);
   system("pause");
   return(0);
}
