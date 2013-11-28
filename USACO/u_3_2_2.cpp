/*
ID: liuq9011
LANG: C++
TASK: kimbits
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("kimbits.in","r");
   out=fopen("kimbits.out","w");
   long long i,j,n,l,m;
   int a[50][50];
   fscanf(in,"%lld%lld%lld",&n,&l,&m);
   memset(a,0,sizeof(a));
   for (i=0;i<=n;i++)
      a[i][0]=1;
   for (i=0;i<=l;i++)
      a[0][i]=1;
   for (i=1;i<=n;i++)
      for (j=1;j<=l;j++)
         a[i][j]=a[i-1][j]+a[i-1][j-1];
   for (i=n-1;i>=0;i--)
      if (m>a[i][l])
      {
         fprintf(out,"1");
         m-=a[i][l];
         l--;
      }
      else
         fprintf(out,"0");
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
