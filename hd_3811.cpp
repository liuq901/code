#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;
int b[140000];
ll c[20],f[140000];
bool a[20][20];
int main()
{
   for (int i=1;i<1<<17;i++)
      b[i]=b[i&i-1]+1;
   c[0]=1;
   for (int i=1;i<=17;i++)
      c[i]=c[i-1]*i;
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(a,0,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]=true;
      }
      memset(f,0,sizeof(f));
      f[0]=1;
      for (int i=0;i<(1<<n)-1;i++)
         for (int j=1;j<=n;j++)
            if (!(i>>j-1&1) && !a[b[i]+1][j])
               f[i|1<<j-1]+=f[i];
      static int id=0;
      printf("Case %d: %I64d\n",++id,c[n]-f[(1<<n)-1]);
   }
   system("pause");
   return(0);
}
