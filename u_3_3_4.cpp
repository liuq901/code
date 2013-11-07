/*
ID: liuq9011
LANG: C++
TASK: range
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("range.in","r");
   out=fopen("range.out","w");
   int min(int,int);
   int n,i,j,k,s;
   int f[260][260];
   char ch;
   fscanf(in,"%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
      {
         fscanf(in,"%c",&ch);
         f[i][j]=ch-'0';
      }
      fscanf(in,"%*c");
   }
   for (i=n-1;i>=1;i--)
      for (j=n-1;j>=1;j--)
      {
         if (f[i][j]==0)
            continue;
         f[i][j]=min(min(f[i+1][j],f[i][j+1]),f[i+1][j+1])+1;
      }
   for (k=2;k<=n;k++)
   {
      s=0;
      for (i=1;i<=n-1;i++)
         for (j=1;j<=n-1;j++)
            if (f[i][j]>=k)
               s++;
      if (s!=0)
         fprintf(out,"%d %d\n",k,s);
   }
   fclose(in),fclose(out);
   return(0);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
