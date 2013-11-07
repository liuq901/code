#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[20];
int main()
{
   int gcd(int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int ans=1;
      for (int i=2;i<=100;i++)
         while (1)
         {
            bool flag=false;
            for (int j=1;j<=n;j++)
            {
               if (a[j]%i)
                  continue;
               flag=true;
               a[j]/=i;
            }
            if (!flag)
               break;
            ans*=i;
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
