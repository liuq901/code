#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   void work(int,int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (n==0 && m==0)
         break;
      work(n,m);
   }
   system("pause");
   return(0);
}
void work(int n,int m)
{
   double p[101][3],a[301][110]={0};
   int sum=0,f[101];
   for (int i=1;i<=n;i++)
   {
      scanf("%lf%lf%lf",&p[i][0],&p[i][1],&p[i][2]);
      if (fabs(p[i][2])>1e-8)
      {
         f[i]=sum+1;
         sum+=3;
      }
      else
         f[i]=-1;
   }
   for (int i=1;i<=m;i++)
   {
      int u,v;
      scanf("%d%d",&u,&v);
      for (int j=0;j<3;j++)
      {
         double delta=p[u][j]-p[v][j];
         if (f[u]!=-1)
            a[f[u]+j][i]=delta;
         if (f[v]!=-1)
            a[f[v]+j][i]=-delta;
      }
   }
   for (int i=1;i<=sum/3;i++)
      a[i*3][m+1]=1;
   bool flag[301]={0};
   for (int i=1;i<=m;i++)
   {
      int k=-1;
      for (int j=1;j<=sum;j++)
         if (!flag[j] && fabs(a[j][i])>1e-8)
         {
            k=j;
            break;
         }
      if (k==-1)
         continue;
      flag[k]=true;
      for (int j=1;j<=sum;j++)
         if (j!=k && fabs(a[j][i])>1e-8)
         {
            double t=a[j][i]/a[k][i];
            for (int l=i+1;l<=m+1;l++)
               a[j][l]-=a[k][l]*t;
         }
   }
   bool ans=false;
   static int id=0;
   printf("Sculpture %d: ",++id);
   for (int i=1;i<=sum;i++)
   {
      if (flag[i])
         continue;
      if (fabs(a[i][m+1])>1e-8)
      {
         printf("NON-STATIC\n");
         return;
      }
      ans=true;
   }
   if (ans)
      printf("UNSTABLE\n");
   else
      printf("STABLE\n");
}
