#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[30];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int A,B;
      scanf("%d%d",&A,&B);
      bool first=true;
      for (int i=1;i<=n;i++)
      {
         int lie=0;
         for (int j=1;j<=n;j++)
            if (a[j]!=i)
               lie++;
         int t=max(0,lie-(n-i));
         if (t>A || n-lie-(i-t)>B)
            continue;
         if (!first)
            printf(" ");
         printf("%d",i);
         first=false;
      }
      if (first)
         printf("impossible");
      printf("\n");
   }
   system("pause");
   return(0);
}
