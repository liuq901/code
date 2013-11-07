#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,ans=-10000000,now=-10000000,max=-10000000;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (x>max)
            max=x;
         if (now+x>0)
         {
            now+=x;
            if (now>ans)
               ans=now;
         }
         else if (x>0)
            now=x;
         else
            now=0;
         if (now>ans)
            ans=now;
      }
      if (max<0)
         ans=max;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
