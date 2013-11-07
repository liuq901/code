#include <cstdio>
#include <cstdlib>
const int mod=1999;
int a[1010];
int main()
{
   a[1]=1;
   for (int i=2;i<=1000;i++)
      a[i]=(a[i-1]*(i-1))%mod;
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      printf("%d\n",a[n]);
   }
   system("pause");
   return(0);
}
