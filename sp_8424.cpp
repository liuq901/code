#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int num=625;
int a[30][30];
bool f[30][30][1300];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,A,B;
      scanf("%d%d%d%d",&n,&m,&A,&B);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      memset(f,0,sizeof(f));
      for (int i=1;i<=m;i++)
         f[1][i][a[1][i]+num]=true;
      for (int i=1;i<n;i++)
         for (int j=1;j<=m;j++)
            for (int k=0;k<=num<<1;k++)
               if (f[i][j][k])
               {
                  f[i+1][j-1][k+a[i+1][j-1]]=true;
                  f[i+1][j][k+a[i+1][j]]=true;
                  f[i+1][j+1][k+a[i+1][j+1]]=true;
               }
      int x=B+1,y=A-1;
      for (int i=1;i<=m;i++)
         for (int j=max(-num,A);j<=min(num,B);j++)
            if (f[n][i][j+num])
               x=min(x,j),y=max(y,j);
      if (x==B+1)
         printf("NO NO\n");
      else
         printf("%d %d\n",x,y);
   }
   system("pause");
   return(0);
}
