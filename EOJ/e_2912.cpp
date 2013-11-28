#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=0;i<n;i++)
         a[i]=i+1;
      int ans=0;
      while (next_permutation(a,a+n))
      {
         bool flag=true;
         for (int i=0;i<n;i++)
            if (a[i]==i+1)
            {
               flag=false;
               break;
            }
         ans+=flag;
         if (flag && n<8)
         {
            for (int i=0;i<n;i++)
               printf("%d",a[i]);
            printf("\n");
         }
      }
      if (n>=8)
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
