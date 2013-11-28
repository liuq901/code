#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,t,s,e;
   scanf("%d%d%d%d",&n,&t,&s,&e);
   int a[101],b[101],len[101],d[101]={0},c[101][101][2];
   for (int i=1;i<=t;i++)
      scanf("%d%d%d",&len[i],&a[i],&b[i]);
   int m=0,f[1001]={0};
   for (int i=1;i<=t;i++)
   {
      if (!f[a[i]])
         f[a[i]]=++m;
      if (!f[b[i]])
         f[b[i]]=++m;
   }
   for (int i=1;i<=t;i++)
   {
      int x,y;
      x=f[a[i]];
      y=f[b[i]];
      d[x]++;
      c[x][d[x]][0]=y;
      c[x][d[x]][1]=len[i];
      d[y]++;
      c[y][d[y]][0]=x;
      c[y][d[y]][1]=len[i];
   }
   int g[201][101][2];
   memset(g,26,sizeof(g));
   g[0][f[s]][0]=g[0][f[e]][1]=0;
   for (int i=1;i<=2*t;i++)
      for (int j=1;j<=m;j++)
         for (int k=1;k<=d[j];k++)
         {
            int x=c[j][k][0];
            g[i][j][0]<?=g[i-1][x][0]+c[j][k][1];
            g[i][j][1]<?=g[i-1][x][1]+c[j][k][1];
         }
   int ans=2000000000;
   for (int i=1;i<=t;i++)
   {
      int x,y;
      x=f[a[i]];
      y=f[b[i]];
      for (int j=0;j<=2*t;j++)
         for (int k=0;k<=2*t;k++)
         {
            if (j+k>n)
               continue;
            if ((n-j-k)%2)
            {
               ans<?=g[j][x][0]+g[k][y][1]+len[i]*(n-j-k);
               ans<?=g[j][x][1]+g[k][y][0]+len[i]*(n-j-k);
            }
            else
            {
               ans<?=g[j][x][0]+g[k][x][1]+len[i]*(n-j-k);
               ans<?=g[j][y][0]+g[k][y][1]+len[i]*(n-j-k);
            }
         }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
