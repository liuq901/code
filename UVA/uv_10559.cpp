#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[201][201][201];
int main()
{
   int work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      printf("Case %d: %d\n",i,work());
   system("pause");
   return(0);
}
int work()
{
   int sqr(int);
   int n,m,i,j,k,p,x;
   int a[201],b[201],color[201],len[201];
   scanf("%d",&n);
   scanf("%d",&x);
   m=1;
   color[1]=x;
   len[1]=1;
   for (i=2;i<=n;i++)
   {
      scanf("%d",&x);
      if (x==color[m])
         len[m]++;
      else
      {
         m++;
         color[m]=x;
         len[m]=1;
      }
   }
   memset(b,0,sizeof(b));
   for (i=m;i>=1;i--)
   {
      x=color[i];
      a[i]=b[x];
      b[x]=i;
   }
   for (i=1;i<=m;i++)
      f[i][i-1][0]=0;
   for (i=m;i>=1;i--)
      for (j=i;j<=m;j++)
         for (k=n;k>=0;k--)
         {
            f[i][j][k]=f[i][j-1][0]+sqr(len[j]+k);
            p=i;
            while (color[p]!=color[j])
               p++;
            while (p<j && p!=0)
            {
               if (f[i][p][len[j]+k]+f[p+1][j-1][0]>f[i][j][k])
                  f[i][j][k]=f[i][p][len[j]+k]+f[p+1][j-1][0];
               p=a[p];
            }
         }
   return(f[1][m][0]);
}
int sqr(int x)
{
   return(x*x);
}
