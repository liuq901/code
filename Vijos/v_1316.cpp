#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x,m,a[1001]={0},s=0;
   scanf("%d",&n);
   for (i=0;i<n;i++)
   {
      scanf("%d",&x);
      if (a[x]==0)
      {
         a[x]=1;
         s++;
      }
   }
   printf("%d\n",s);
   m=0;
   for (i=1;i<=1000;i++)
      if (a[i]!=0)
      {
         m++;
         if (m<s)
            printf("%d ",i);
         else
         {
            printf("%d\n",i);
            break;
         }
      }
   system("pause");
   return(0);
}
