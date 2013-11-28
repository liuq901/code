#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[30],b[30],f[30][4010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      int m=0;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&b[i]);
         m+=a[i]*b[i];
      }
      memset(f,0,sizeof(f));
      f[0][0]=true;
      for (int i=1;i<=n;i++)
         for (int j=0;j<=b[i];j++)
            for (int k=0;k<=m-a[i]*j;k++)
               if (f[i-1][k])
                  f[i][k+a[i]*j]=true;
      printf("%d\n",count(f[n],f[n]+m+1,true));
   }
   system("pause");
   return(0);
}
