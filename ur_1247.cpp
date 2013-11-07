#include <cstdio>
#include <cstdlib>
int main()
{
   int n,k,ans,now;
   ans=-1<<30,now=0;
   scanf("%d%d",&n,&k);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      x--;
      if (now+x<x)
         now=x;
      else
         now+=x;
      if (now>ans)
         ans=now;
   }
   printf("%s\n",ans<=k?"YES":"NO");
   system("pause");
   return(0);
}
