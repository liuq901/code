#include <cstdio>
#include <cstdlib>
const double eps=1e-7;
int main()
{
   double x;
   while (scanf("%lf",&x)!=EOF)
   {
      if (x<eps)
         break;
      double s=0;
      int ans=1;
      while (1)
      {
         ans++;
         s+=1.0/ans;
         if (s>=x)
         {
            printf("%d card(s)\n",ans-1);
            break;
         }
      }
   }
   system("pause");
   return(0);
}
