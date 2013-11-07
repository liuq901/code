#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n;
   int x[20000],y[20000],a[20000],ans[20000];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (x[j]<=x[i] && y[j]<=y[i])
            a[i]++;
   memset(ans,0,sizeof(ans));
   for (i=1;i<=n;i++)
      ans[a[i]-1]++;
   for (i=0;i<=n-1;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
