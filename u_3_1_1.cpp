/*
ID: liuq9011
LANG: C++
TASK: agrinet
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("agrinet.in","r");
   out=fopen("agrinet.out","w");
   int i,j,k,n,min,ans;
   int c[101],f[101],a[101][101];
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         fscanf(in,"%d",&a[i][j]);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      c[i]=a[1][i];
   f[1]=1;
   ans=0;
   for (i=2;i<=n;i++)
   {
      k=0;
      min=200000;
      for (j=2;j<=n;j++)
         if (!f[j] && c[j]<min)
         {
            min=c[j];
            k=j;
         }
      for (j=2;j<=n;j++)
         if (a[k][j]<c[j])
            c[j]=a[k][j];
      f[k]=1;
      ans+=min;
   }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
