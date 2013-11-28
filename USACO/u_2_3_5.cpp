/*
ID: liuq9011
LANG: C++
TASK: concom
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int m,a[101][101],b[101],f[101];
int main()
{
   in=fopen("concom.in","r");
   out=fopen("concom.out","w");
   void search(int);
   int i,j,n,x,y,z;
   fscanf(in,"%d",&n);
   memset(a,0,sizeof(a));
   m=0;
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%d%d",&x,&y,&z);
      if (x>m)
         m=x;
      if (y>m)
         m=y;
      a[x][y]=z;
   }
   for (i=1;i<=m;i++)
   {
      for (j=1;j<=m;j++)
         b[j]=a[i][j];
      memset(f,0,sizeof(f));
      f[i]=1;
      for (j=1;j<=m;j++)
         if (i!=j && !f[j] && b[j]>=50)
         {
            f[j]=1;
            search(j);
         }
      for (j=1;j<=m;j++)
         if (b[j]>=50 && i!=j)
            fprintf(out,"%d %d\n",i,j);
   }
   fclose(in),fclose(out);
   return(0);
}
void search(int y)
{
   int i;
   for (i=1;i<=m;i++)
   {
      if (b[y]>=50)
         b[i]+=a[y][i];
      if (b[i]>=50 && !f[i])
      {
         f[i]=1;
         search(i);
      }
   }
}
