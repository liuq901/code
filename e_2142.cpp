#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      int ans=0,now=k;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (x>now)
            ans++,now=k;
         now-=x;
      }
      ans+=(now!=k);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
