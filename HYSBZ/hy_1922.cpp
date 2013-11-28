#include <cstdio>
#include <cstdlib>
int b[3001],a[70001][3],link[3001],c[500001][2];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   int d[3001]={0};
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y;
      a[i][1]=z;
      a[i][2]=b[x];
      b[x]=i;
   }
   int t=0;
   for (int i=1;i<=n;i++)
   {
      int k;
      scanf("%d",&k);
      for (int j=1;j<=k;j++)
      {
         int x;
         scanf("%d",&x);
         c[++t][0]=i;
         c[t][1]=link[x];
         link[x]=t;
      }
      d[i]+=k;
   }
   long long dist[3001],last[3001]={0};
   bool f[3001]={0};
   for (int i=0;i<=n;i++)
      dist[i]=1LL<<60;
   dist[1]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!f[j] && !d[j] && dist[j]<dist[k])
            k=j;
      if (!k)
         break;
      f[k]=true;
      for (int j=b[k];j;j=a[j][2])
      {
         int x=a[j][0];
         if (f[x])
            continue;
         if (dist[k]+a[j][1]<dist[x])
            dist[x]=dist[k]+a[j][1];
      }
      for (int j=link[k];j;j=c[j][1])
      {
         int x=c[j][0];
         d[x]--;
         if (dist[k]>last[x])
            last[x]=dist[k];
         if (dist[x]<last[x])
            dist[x]=last[x];
      }
   }
   printf("%I64d\n",dist[n]);
   system("pause");
   return(0);
}
