/*
ID: liuq9011
LANG: C++
TASK: tour
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("tour.in","r");
   out=fopen("tour.out","w");
   int n,m,i,j,k,p,q,ans;
   int a[101][101],f[101][101];
   char x[20],y[20],s[101][20];
   fscanf(in,"%d%d%*c",&n,&m);
   for (i=1;i<=n;i++)
      fscanf(in,"%s",s[i]);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      fscanf(in,"%s %s",x,y);
      for (j=1;j<=n;j++)
      {
         if (strcmp(x,s[j])==0)
            p=j;
         if (strcmp(y,s[j])==0)
            q=j;
      }
      a[p][q]=a[q][p]=1;
   }
   memset(f,-26,sizeof(f));
   f[1][1]=1;
   for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
      {
         for (k=1;k<j;k++)
            if (a[k][j] && f[i][k]>0 && f[i][k]+1>f[i][j])
               f[i][j]=f[i][k]+1;
         f[j][i]=f[i][j];
      }
   ans=1;
   for (i=1;i<=n;i++)
      if (a[i][n] && f[i][n]>ans)
         ans=f[i][n];
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
