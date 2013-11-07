#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   for (int i=1;i<=13000;i++)
   {
      int x=i*(i+1)>>1,limit=int(sqrt(x))+2,sum=0;
      for (int j=1;j<=limit;j++)
      {
         if (x%j)
            continue;
         int p=j,q=x/j;
         if (p>q)
            break;
         else if (p==q)
            sum++;
         else
            sum+=2;
      }
      if (sum>500)
         printf("%d\n",x);
   }
   system("pause");
   return(0);
}
