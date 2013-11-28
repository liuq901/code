#include <cstdio>
#include <cstdlib>
int n;
double a[101][101],g[101][101],f[101][101][101];
int main()
{
   double calc(int,int,int);
   int i,j,k;
   double s,t,x;
   double d[101];
   scanf("%d",&n);
   s=t=0;
   for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
      {
         for (k=0;k<=n;k++)
            f[i][j][k]=-1;
         g[i][j]=-1;
         a[i][j]=-1;
      }
   for (i=2;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         x=calc(n,i,j);
         s+=x*i*j;
         t+=x;
      }
   printf("%.12lf\n",s/t);
   system("pause");
   return(0);
}
double calc(int i,int j,int k)
{
   double get(int,int),count(int,int);
   int min(int,int);
   int l;
   if (f[i][j][k]!=-1)
      return(f[i][j][k]);
   if (i==j && i>1 && k==1)
      f[i][j][k]=get(i,n)/i;
   else if (j>=2 && j<=i-2 && k>1 && k<=i/j)
      f[i][j][k]=calc(i-j,j,k-1)*get(j,n-i+j)/j/k;
   else if (j>=2 && j<=i-2 && k==1)
   {
      f[i][j][k]=0;
      for (l=2;l<=min(j-1,i-j);l++)
         f[i][j][k]+=count(i-j,l);
      f[i][j][k]*=get(j,n-i+j)/j;
   }
   else
      f[i][j][k]=0;
   return(f[i][j][k]);
}
double get(int x,int y)
{
   int i;
   if (a[x][y]!=-1)
      return(a[x][y]);
   if (x>y)
      a[x][y]=0;
   else
   {
      a[x][y]=1;
      for (i=y;i>=y-x+1;i--)
         a[x][y]*=i;
   }
   return(a[x][y]);
}
double count(int i,int j)
{
   double calc(int,int,int);
   int k;
   if (g[i][j]!=-1)
      return(g[i][j]);
   g[i][j]=0;
   for (k=1;k<=i/j;k++)
      g[i][j]+=calc(i,j,k);
   return(g[i][j]);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
