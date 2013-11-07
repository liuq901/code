#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      double s=0;
      for (int i=1;i<=n;i++)
         s+=double(n)/i;
      printf("%.2lf\n",s);
   }
   system("pause");
   return(0);
}
