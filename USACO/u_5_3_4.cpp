/*
ID: liuq9011
LANG: C++
TASK: bigbrn
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[1001][1001],f[1001][1001];
int main()
{
   in=fopen("bigbrn.in","r");
   out=fopen("bigbrn.out","w");
   int min(int,int,int);
   int n,t,i,j,x,y,ans;
   fscanf(in,"%d%d",&n,&t);
   memset(a,0,sizeof(a));
   for (i=1;i<=t;i++)
   {
      fscanf(in,"%d%d",&x,&y);
      a[x][y]=1;
   }
   ans=0;
   for (i=n;i>=1;i--)
      for (j=n;j>=1;j--)
      {
         if (a[i][j])
         {
            f[i][j]=0;
            continue;
         }
         if (i==n || j==n)
            f[i][j]=1;
         else
            f[i][j]=min(f[i+1][j],f[i][j+1],f[i+1][j+1])+1;
         if (f[i][j]>ans)
            ans=f[i][j];
      }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int min(int x,int y,int z)
{
   if (y<x)
      x=y;
   if (z<x)
      x=z;
   return(x);
}
