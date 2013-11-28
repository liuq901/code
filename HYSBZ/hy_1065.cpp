#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int n,m,p[100],s[100],map[100][100];
double ans,x,num,c[100],g[100],f[100][100][100];
int main()
{
   void work(int);
   int i,t;
   scanf("%d%d%lf",&n,&m,&num);
   for (i=1;i<=n;i++)
      scanf("%d",&s[i]);
   for (i=1;i<=n;i++)
      scanf("%lf",&c[i]);
   ans=0;
   work(m);
   i=s[1];
   while (s[i]!=1)
   {
      t=s[i];
      s[i]=1;
      work(m-1);
      s[i]=t;
      i=s[i];
   }
   printf("%.2lf\n",ans);
   system("pause");
   return(0);
}
void work(int t)
{
   void count(int,int);
   int i,j,ii,jj;
   int circle[100];
   memset(circle,0,sizeof(circle));
   i=1;
   j=0;
   while (1)
   {
      circle[i]=1;
      i=s[i];
      j++;
      if (circle[i])
         break;
   }
   memset(p,0,sizeof(p));
   for (i=1;i<=n;i++)
   {
      if (circle[i])
         continue;
      p[s[i]]++;
      map[s[i]][p[s[i]]]=i;
   }
   i=1;
   x=1/(1-pow(num,j));
   memset(g,0,sizeof(g));
   while (1)
   {
      i=s[i];
      j--;
      count(i,j);
      ii=i;
      jj=j;
      for (i=t;i>=0;i--)
         for (j=0;j<=i;j++)
            if (g[i-j]+f[ii][jj][j]>g[i])
               g[i]=g[i-j]+f[ii][jj][j];
      i=ii;
      j=jj;
      if (i==1)
         break;
   }
   if (g[t]>ans)
      ans=g[t];
}
void count(int t,int d)
{
   int i,j,k,l;
   double tmp;
   memset(f[t],0,sizeof(f[t]));
   for (i=1;i<=p[t];i++)
   {
      count(map[t][i],d+1);
      for (j=0;j<=d;j++)
         for (k=m;k>=0;k--)
         {
            for (l=0;l<=k;l++)
               if (f[t][j][k-l]+f[map[t][i]][j+1][l]>f[t][j][k])
                  f[t][j][k]=f[t][j][k-l]+f[map[t][i]][j+1][l];
            for (l=1;l<=k;l++)
               if (f[t][j][k-l]+f[map[t][i]][1][l-1]>f[t][j][k])
                  f[t][j][k]=f[t][j][k-l]+f[map[t][i]][1][l-1];
         }
   }
   for (i=0;i<=d;i++)
   {
      tmp=c[t]*pow(num,i)*x;
      for (j=0;j<=m;j++)
         f[t][i][j]=f[t][i][j]+tmp;
   }
}
