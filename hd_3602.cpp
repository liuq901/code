#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,K,a[110],b[110],f[110][110],g[110][110];
int main()
{
   void init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d%d",&n,&m,&K);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i],&b[i]);
         a[i]++;
      }
      init();
      memset(f,-63,sizeof(f));
      for (int i=0;i<=m;i++)
         f[i][0]=0;
      for (int i=0;i<=n;i++)
         f[0][i]=0;
      for (int i=1;i<=m;i++)
         for (int j=1;j<=n;j++)
            for (int k=0;k<j;k++)
               f[i][j]=max(f[i][j],f[i-1][k]+g[k+1][j]);
      printf("%d\n",f[m][n]);
   }
   system("pause");
   return(0);
}
int v[10010];
void init()
{
   for (int i=1;i<=n;i++)
   {
      memset(v,63,sizeof(v));
      int now=0;
      v[0]=0;
      for (int j=i;j<=n;j++)
      {
         for (int k=now+b[j];k>=b[j];k--)
            v[k]=min(v[k],v[k-b[j]]+a[j]);
         for (int k=now+b[j];k>=0;k--)
            if (v[k]<=K)
            {
               g[i][j]=now=k;
               break;
            }
      }
   }
}
