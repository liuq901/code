#include <cstdio>
#include <cstdlib>
const int q=10000;
int a[2600];
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      a[0]=a[1]=1;
      for (int i=1;i<=m;i++)
      {
         int x=0;
         for (int j=1;j<=a[0];j++)
         {
            a[j]=a[j]*n+x;
            x=a[j]/q;
            a[j]%=q;
         }
         while (x)
         {
            a[++a[0]]=x%q;
            x/=q;
         }
      }
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i>=1;i--)
         printf("%04d",a[i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
