#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const long double epsilon=1e-7;
long double a[51][51];
int main()
{
   long double solve(int);
   int n,m;
   while (scanf("%d%d%*d",&n,&m)!=EOF)
   {
      bool f[51][51]={0};
      memset(a,0,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         f[x][y]=f[y][x]=true;
      }
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            if (f[i][j])
               continue;
            a[i][j]--;
            a[j][i]--;
            a[i][i]++;
            a[j][j]++;
         }
      printf("%.0lf\n",double(solve(n-1)));
   }
   system("pause");
   return(0);
}
long double solve(int n)
{
   long double ans=1;
   for (int i=1;i<=n;i++)
   {
      if (fabs(a[i][i])<epsilon)
      {
         int k=0;
         for (int j=i+1;j<=n;j++)
            if (fabs(a[i][j])>epsilon)
            {
               k=j;
               break;
            }
         if (!k)
            return(0);
         for (int j=i;j<=n;j++)
         {
            long double t;
            t=a[j][i],a[j][i]=a[j][k],a[j][k]=t;
         }
      }
      for (int j=i+1;j<=n;j++)
      {
         long double p=a[i][j]/a[i][i];
         for (int k=i;k<=n;k++)
            a[k][j]-=p*a[k][i];
      }
      ans*=a[i][i];
   }
   return(fabs(ans));
}
