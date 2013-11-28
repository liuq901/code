#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      int ans=1,sum=1,now=1;
      for (int i=2;i<=50;i++)
      {
         sum+=now;
         now+=n;
         ans+=sum;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
