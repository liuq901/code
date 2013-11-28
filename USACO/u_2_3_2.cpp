/*
ID: liuq9011
LANG: C++
TASK: nocows
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("nocows.in","r");
   out=fopen("nocows.out","w");
   int n,k,i,j,l;
   int f[201][101];
   fscanf(in,"%d%d",&n,&k);
   memset(f,0,sizeof(f));
   for (i=1;i<=k;i++)
      f[1][i]=1;
   for (i=1;i<=n;i++)
      if (n%2==1)
      {
         for (j=1;j<=k;j++)
            for (l=1;l<=i-2;l++)
            {
               f[i][j]+=f[l][j-1]*f[i-l-1][j-1];
               f[i][j]%=9901;
            }
      }
   fprintf(out,"%d\n",(f[n][k]-f[n][k-1]+9901)%9901);
   fclose(in),fclose(out);
   return(0);
}
