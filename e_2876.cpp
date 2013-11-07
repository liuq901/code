#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      int ans=0;
      while (x || y)
      {
         ans+=(x&1)!=(y&1);
         x>>=1,y>>=1;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
