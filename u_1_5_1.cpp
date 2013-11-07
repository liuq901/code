/*
ID: liuq9011
LANG: C++
TASK: numtri
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[1001][1001],f[1001][1001];
int main()
{
   in=fopen("numtri.in","r");
   out=fopen("numtri.out","w");
   int i,j,n,ans;
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=i;j++)
         fscanf(in,"%d",&a[i][j]);
   memset(f,0,sizeof(f));
   f[1][1]=a[1][1];
   for (i=2;i<=n;i++)
      for (j=1;j<=i;j++)
      {
         if (j>1 && a[i][j]+f[i-1][j-1]>f[i][j])
            f[i][j]=a[i][j]+f[i-1][j-1];
         if (a[i][j]+f[i-1][j]>f[i][j])
            f[i][j]=a[i][j]+f[i-1][j];
      }
   ans=0;
   for (i=1;i<=n;i++)
      if (f[n][i]>ans)
         ans=f[n][i];
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
