#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      double n;
      scanf("%lf",&n);
      if (n==0)
         break;
      int ans=1;
      double sum=0;
      while (sum<n)
         sum+=1.0/++ans;
      printf("%d card(s)\n",ans-1);
   }
   system("pause");
   return(0);
}
