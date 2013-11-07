#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int d[1000010];
int main()
{
   void init();
   init();
   int ans=1;
   for (int i=1;i<=1000000;i*=10)
      ans*=d[i];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int a[10000];
void init()
{
   int t=0;
   for (int i=1;;i++)
   {
      int n=0,x=i;
      while (x)
      {
         a[++n]=x%10;
         x/=10;
      }
      reverse(a+1,a+n+1);
      for (int i=1;i<=n;i++)
      {
         d[++t]=a[i];
         if (t==1000000)
            return;
      }
   }
}
