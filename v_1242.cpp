#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int v,p,i,j,k,t;
   int a[301],s[301][301],f[301][31],pa[301][31];
   scanf("%d%d",&v,&p);
   for (i=1;i<=v;i++)
      scanf("%d",&a[i]);
   memset(s,0,sizeof(s));
   for (i=1;i<=v;i++)
      for (j=i;j<=v;j++)
      {
         t=(i+j)/2;
         for (k=i;k<=j;k++)
            s[i][j]+=abs(a[k]-a[t]);
      }
   memset(f,31,sizeof(f));
   for (i=1;i<=v;i++)
      f[i][1]=s[1][i];
   for (i=1;i<=v;i++)
      for (j=2;j<=p;j++)
         for (k=j-1;k<=i-1;k++)
            if (f[k][j-1]+s[k+1][i]<f[i][j])
               f[i][j]=f[k][j-1]+s[k+1][i];
   printf("%d\n",f[v][p]);
   system("pause");
   return(0);
}
