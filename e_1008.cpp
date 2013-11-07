#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      int ans=0;
      while (n)
      {
         ans+=n/5;
         n/=5;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
