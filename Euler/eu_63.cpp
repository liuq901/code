#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int ans=0;
   for (int i=1;i<=9;i++)
      for (int j=1;;j++)
      {
         int p=int(ceil(log10(pow(i,j))));
         if (p!=j)
            break;
         ans++;
      }
   printf("%d\n",ans+1);
   system("pause");
   return(0);
}
