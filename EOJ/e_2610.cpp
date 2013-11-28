#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,ans=0;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ans+=x*(i<=m);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
