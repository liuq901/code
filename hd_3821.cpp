#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1010],b[1000010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
         {
            int x;
            scanf("%d",&x);
            if (x)
               a[i]=j;
         }
      b[0]=0;
      while (1)
      {
         bool flag=false;
         for (int i=0;i<n-1;i++)
            if (a[i]>a[i+1])
            {
               swap(a[i],a[i+1]);
               b[++b[0]]=i;
               flag=true;
            }
         if (!flag)
            break;
      }
      static int id=0;
      printf("Case %d: %d\n",++id,b[0]);
      if (!b[0])
         printf("\n");
      else
         for (int i=1;i<=b[0];i++)
            printf("%d%c",b[i],i==b[0]?'\n':' ');
   }
   system("pause");
   return(0);
}
