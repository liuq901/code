#include <cstdio>
#include <cstdlib>
#include <bitset>
using namespace std;
bitset <1000010> f;
int a[310];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int ans=1;
      while (1)
      {
         f.reset();
         bool flag=true;
         for (int i=1;i<=n;i++)
         {
            if (f.test(a[i]%ans))
            {
               flag=false;
               break;
            }
            f.set(a[i]%ans);
         }
         if (flag)
            break;
         ans++;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
