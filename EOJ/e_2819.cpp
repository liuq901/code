#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      int ans=0,p=0;
      while (n)
      {
         ans+=n;
         p+=n;
         n=p/3;
         p%=3;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
