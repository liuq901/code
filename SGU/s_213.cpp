#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[401][401],c[160001][2];
int main()
{
   int n,m,s,t,i,j,k,min,ans;
   int f[401],d[401],a[401][401];
   scanf("%d%d%d%d",&n,&m,&s,&t);
   memset(a,26,sizeof(a));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&c[i][0],&c[i][1]);
      a[c[i][0]][c[i][1]]=1;
      a[c[i][1]][c[i][0]]=1;
   }
   memset(d,26,sizeof(d));
   memset(f,0,sizeof(f));
   d[s]=0;
   for (i=1;i<=n;i++)
   {
      k=0;
      min=2000000;
      for (j=1;j<=n;j++)
         if (!f[j] && d[j]<min)
         {
            min=d[j];
            k=j;
         }
      if (k==0)
         break;
      f[k]=1;
      for (j=1;j<=n;j++)
         if (!f[j] && d[k]+a[k][j]<d[j])
            d[j]=d[k]+a[k][j];
   }
   printf("%d\n",d[t]);
   memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   {
      if (d[c[i][0]]>d[t] || d[c[i][1]]>d[t])
      {
         b[i%d[t]+1][0]++;
         b[i%d[t]+1][b[i%d[t]+1][0]]=i;
         continue;
      }
      if (d[c[i][0]]==d[c[i][1]]+1)
      {
         b[d[c[i][0]]][0]++;
         b[d[c[i][0]]][b[d[c[i][0]]][0]]=i;
         continue;
      }
      if (d[c[i][1]]==d[c[i][0]]+1)
      {
         b[d[c[i][1]]][0]++;
         b[d[c[i][1]]][b[d[c[i][1]]][0]]=i;
         continue;
      }
      b[i%d[t]+1][0]++;
      b[i%d[t]+1][b[i%d[t]+1][0]]=i;
   }
   for (i=1;i<=d[t];i++)
   {
      printf("%d",b[i][0]);
      for (j=1;j<=b[i][0];j++)
         printf(" %d",b[i][j]);
      printf("\n");
   }
   system("pause");
   return(0);
}
