#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;
ll f[60][40];
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      memset(f,0,sizeof(f));
      f[0][0]=1;
      int limit=(1<<m)-1;
      for (int i=0;i<n;i++)
         for (int j=0;j<limit;j++)
         {
            f[i+1][j<<1&limit]+=f[i][j];
            f[i+1][(j<<1)+1&limit]+=f[i][j];
         }
      ll ans=0;
      for (int i=0;i<limit;i++)
         ans+=f[n][i];
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
