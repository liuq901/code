#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,k,x,y,ans;
   scanf("%d%d",&n,&k);
   ans=0;
   for (i=1;i<=n;i++)
   {
      y=0;
      while (1)
      {
         scanf("%d",&x);
         if (x!=0)
            y++;
         else
            break;
      }
      if (y>=k)
         ans++;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
