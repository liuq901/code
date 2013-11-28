/*
ID: liuq9011
LANG: C++
TASK: game1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int f[101][101],s[101][101];
int main()
{
   in=fopen("game1.in","r");
   out=fopen("game1.out","w");
   int work(int,int);
   int n,i,j,k,t;
   int a[101];
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&a[i]);
   memset(s,0,sizeof(s));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         for (k=i;k<=j;k++)
            s[i][j]+=a[k];
   memset(f,-1,sizeof(f));
   t=work(1,n);
   fprintf(out,"%d %d\n",t,s[1][n]-t);
   fclose(in),fclose(out);
   return(0);
}
int work(int l,int r)
{
   int min(int,int);
   if (f[l][r]!=-1)
      return(f[l][r]);
   if (l==r)
      return(s[l][r]);
   f[l][r]=s[l][r]-min(work(l,r-1),work(l+1,r));
   return(f[l][r]);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
