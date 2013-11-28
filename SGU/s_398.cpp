#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,i,j,x,t,min;
   int ans[51],f[51],cost[51],a[51][51];
   scanf("%d%d",&n,&x);
   memset(a,26,sizeof(a));
   for (i=1;i<=n;i++)
   {
      scanf("%d",&m);
      for (j=1;j<=m;j++)
      {
         scanf("%d",&t);
         a[i][t]=1;
         a[t][i]=1;
      }
      a[i][i]=0;
   }
   memset(cost,26,sizeof(cost));
   memset(f,0,sizeof(f));
   cost[x]=0;
   for (i=1;i<=n;i++)
   {
      min=20000000;
      t=0;
      for (j=1;j<=n;j++)
         if (!f[j] && cost[j]<min)
         {
            min=cost[j];
            t=j;
         }
      if (t==0)
         break;
      f[t]=1;
      for (j=1;j<=n;j++)
         if (a[t][j]+cost[t]<cost[j])
            cost[j]=a[t][j]+cost[t];
   }
   ans[0]=0;
   for (i=1;i<=n;i++)
      if (cost[i]==2)
      {
         ans[0]++;
         ans[ans[0]]=i;
      }
   printf("%d\n",ans[0]);
   for (i=1;i<=ans[0]-1;i++)
      printf("%d ",ans[i]);
   if (ans[0]!=0)
      printf("%d\n",ans[ans[0]]);
   system("pause");
   return(0);
}
