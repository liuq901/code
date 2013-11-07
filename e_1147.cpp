#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m,a[50];
      bool flag=false;
      scanf("%d%d",&n,&m);
      if (n<0)
      {
         flag=true;
         n=-n;
      }
      int t=0;
      while (n)
      {
         a[++t]=n%m;
         n/=m;
      }
      if (flag)
         printf("-");
      for (int i=t;i>=1;i--)
         if (a[i]<10)
            printf("%d",a[i]);
         else
            printf("%c",a[i]-10+'A');
      printf("\n");
   }
   system("pause");
   return(0);
}
