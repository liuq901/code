/*
ID: liuq9011
LANG: C++
TASK: subset
*/
#include <cstdio>
#include <cmath>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("subset.in","r");
   out=fopen("subset.out","w");
   int i,j,k,n;
   unsigned int f[100][2000];
   fscanf(in,"%d",&n);
   memset(f,0,sizeof(f));
   f[0][1000]=1;
   for (i=1;i<=n;i++)
   {
      k=i*(i+1)/2;
      for (j=-k;j<=k;j++)
         f[i][j+1000]=f[i-1][j-i+1000]+f[i-1][j+i+1000];
   }
   fprintf(out,"%u\n",f[n][1000]/2);
   fclose(in),fclose(out);
   return(0);
}
