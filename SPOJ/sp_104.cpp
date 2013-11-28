#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const double epsilon=1e-7;
double a[13][13];
int main()
{
   double solve(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(a,0,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]--;
         a[y][x]--;
         a[x][x]++;
         a[y][y]++;
      }
      n--;
      printf("%.0lf\n",solve(n));
   }
   system("pause");
   return(0);
}
double solve(int n)
{
   double ans=1;
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
            double t;
            t=a[j][i],a[j][i]=a[j][k],a[j][k]=t;
         }
      }
      for (int j=i+1;j<=n;j++)
      {
         double p=a[i][j]/a[i][i];
         for (int k=i;k<=n;k++)
            a[k][j]-=p*a[k][i];
      }
      ans*=a[i][i];
   }
   return(fabs(ans));
}
