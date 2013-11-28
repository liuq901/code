#include <cstdio>
#include <cstdlib>
#include <cstring>
const double eps=1e-6;
int n,m,pre[51],a[2501][4];
double v[2501];
int main()
{
   bool bellman_ford(double);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
      scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
   double l=0,r=101,ans=-1;
   while (r-l>eps)
   {
      double mid=(l+r)/2;
      if (bellman_ford(mid))
      {
         ans=mid;
         l=mid;
      }
      else
         r=mid;
   }
   if (ans<0)
      printf("0\n");
   else
   {
      bellman_ford(ans);
      for (int i=1;i<=n;i++)
      {
         int k=i,p[51];
         bool flag=false;
         p[0]=0;
         while (1)
         {
            k=pre[k];
            p[0]++;
            if (!k || p[0]>n)
               break;
            p[p[0]]=k;
            if (k==i)
            {
               flag=true;
               break;
            }
         }
         if (flag)
         {
            printf("%d\n",p[0]);
            for (int j=p[0];j>1;j--)
               printf("%d ",p[j]);
            printf("%d\n",p[1]);
            break;
         }
      }
   }
   system("pause");
   return(0);
}
bool bellman_ford(double k)
{
   double d[51];
   memset(d,0,sizeof(d));
   memset(pre,0,sizeof(pre));
   for (int i=1;i<=m;i++)
      v[i]=a[i][3]*k-a[i][2];
   for (int i=1;i<=n+1;i++)
   {
      bool flag=false;
      for (int j=1;j<=m;j++)
      {
         int x=a[j][0],y=a[j][1];
         if (d[x]+v[j]<d[y])
         {
            flag=true;
            d[y]=d[x]+v[j];
            pre[y]=x;
         }
      }
      if (!flag)
         return(false);
   }
   return(true);
}
