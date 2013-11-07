#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   while (1)
   {
      int mi=100,ma=-1,sum=0,a[10];
      for (int i=1;i<=6;i++)
      {
         scanf("%d",&a[i]);
         mi=min(mi,a[i]);
         ma=max(ma,a[i]);
         sum+=a[i];
      }
      if (!mi && !ma)
         break;
      printf("%g\n",(sum-mi-ma)/4.0);
   }
   system("pause");
   return(0);
}
