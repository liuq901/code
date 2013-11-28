#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[101][101][101][3];
int main()
{
   int max(int,int),min(int,int);
   int n,m,i,j,k,l,p,q,ans;
   int a[101][3];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
   memset(f,0,sizeof(f));
   for (i=0;i<=m;i++)
      for (j=0;j<=n;j++)
         for (k=0;k<=n;k++)
            for (l=0;l<=2;l++)
            {
               if (l==0)
                  p=1,q=2;
               else if (l==1)
                  p=0,q=2;
               else
                  p=0,q=1;
               if (i<m && j<n)
               {
                  if (f[i+1][j+1][j+1][0]<f[i][j][k][l]+a[j+1][0])
                     f[i+1][j+1][j+1][0]=f[i][j][k][l]+a[j+1][0];
                  if (f[i+1][j+1][j+1][1]<f[i][j][k][l]+a[j+1][1])
                     f[i+1][j+1][j+1][1]=f[i][j][k][l]+a[j+1][1];
                  if (f[i+1][j+1][j+1][2]<f[i][j][k][l]+a[j+1][2])
                     f[i+1][j+1][j+1][2]=f[i][j][k][l]+a[j+1][2];
               }
               if (i>0 && j<n)
               {
                  if (f[i][j+1][j+1][0]<f[i][j][k][l]+a[j+1][0])
                     if (max(a[k][p],a[k][q])>=max(a[j+1][1],a[j+1][2]))
                        if (min(a[k][p],a[k][q])>=min(a[j+1][1],a[j+1][2]))
                           f[i][j+1][j+1][0]=f[i][j][k][l]+a[j+1][0];
                  if (f[i][j+1][j+1][1]<f[i][j][k][l]+a[j+1][1])
                     if (max(a[k][p],a[k][q])>=max(a[j+1][0],a[j+1][2]))
                        if (min(a[k][p],a[k][q])>=min(a[j+1][0],a[j+1][2]))
                           f[i][j+1][j+1][1]=f[i][j][k][l]+a[j+1][1];
                  if (f[i][j+1][j+1][2]<f[i][j][k][l]+a[j+1][2])
                     if (max(a[k][p],a[k][q])>=max(a[j+1][0],a[j+1][1]))
                        if (min(a[k][p],a[k][q])>=min(a[j+1][0],a[j+1][1]))
                           f[i][j+1][j+1][2]=f[i][j][k][l]+a[j+1][2];
               }
               if (i>0 && j<n && f[i][j+1][k][l]<f[i][j][k][l])
                  f[i][j+1][k][l]=f[i][j][k][l];
            }
   ans=0;
   for (i=1;i<=n;i++)
      for (j=0;j<=2;j++)
         if (f[m][n][i][j]>ans)
            ans=f[m][n][i][j];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
