#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int ans=0;
      for (int i=1;i<=n;i++)
         ans+=SQR(n-i+1);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
