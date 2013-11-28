#include <cstdio>
#include <cstdlib>
#include <cstring>
const int mod=1000000;
int a[110];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      memset(a,0,sizeof(a));
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%*d%d",&x);
         a[x]++;
         for (int j=x+1;j<100;j++)
            ans=(ans+a[j])%mod;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
