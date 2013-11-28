/*
ID: liuq9011
LANG: C++
TASK: inflate
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("inflate.in","r");
   out=fopen("inflate.out","w");
   int i,j,n,m;
   int a[10001],b[10001],f[10001];
   fscanf(in,"%d%d",&m,&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d%d",&a[i],&b[i]);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      for (j=b[i];j<=m;j++)
         if (a[i]+f[j-b[i]]>f[j])
            f[j]=a[i]+f[j-b[i]];
   fprintf(out,"%d\n",f[m]);
   fclose(in),fclose(out);
   return(0);
}
