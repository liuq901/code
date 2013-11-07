/*
ID: liuq9011
LANG: C++
TASK: fence6
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("fence6.in","r");
   out=fopen("fence6.out","w");
   int i,j,k,n,x,y,s1,s2,ans;
   int a[101],b[101][101],f[101][101],c[101][101];
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%d%d%d",&x,&y,&s1,&s2);
      a[x]=y;
      for (j=1;j<=s1;j++)
         fscanf(in,"%*d");
      for (j=1;j<=s2;j++)
         fscanf(in,"%*d");
   }
   fclose(in);
   in=fopen("fence6.in","r");
   fscanf(in,"%*d");
   memset(b,31,sizeof(b));
   memset(f,31,sizeof(f));
   memset(c,0,sizeof(c));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%*d%d%d",&x,&s1,&s2);
      for (j=1;j<=s1;j++)
      {
         fscanf(in,"%d",&y);
         b[x][y]=a[x]+a[y];
         b[y][x]=b[x][y];
         f[x][y]=b[x][y];
         f[y][x]=b[y][x];
         c[x][y]=1;
      }
      for (j=1;j<=s2;j++)
      {
         fscanf(in,"%d",&y);
         b[x][y]=a[x]+a[y];
         b[y][x]=b[x][y];
         f[x][y]=b[x][y];
         f[y][x]=b[y][x];
         c[x][y]=2;
      }
      b[i][i]=0;
      f[i][i]=0;
   }
   ans=20000000;
   for (k=1;k<=n;k++)
   {
      for (i=1;i<=k-1;i++)
         for (j=i+1;j<=k-1;j++)
            if (c[k][i]!=c[k][j] && f[i][j]+b[i][k]+b[k][j]<ans)
               ans=f[i][j]+b[i][k]+b[k][j];
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
            if (f[i][k]+f[k][j]<f[i][j])
               f[i][j]=f[i][k]+f[k][j];
   }
   fprintf(out,"%d\n",ans/2);
   fclose(in),fclose(out);
   return(0);
}
