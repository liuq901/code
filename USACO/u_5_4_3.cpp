/*
ID: liuq9011
LANG: C++
TASK: charrec
*/
#include <cstdio>
#include <cstring>
FILE *in,*out,*font;
const char letter[]=" abcdefghijklmnopqrstuvwxyz";
int prev[1201],bit[1049000];
char c[1201][3];
int main()
{
   in=fopen("charrec.in","r");
   out=fopen("charrec.out","w");
   font=fopen("font.in","r");
   void scan(FILE *,int *),print(int);
   int n,i,j,k,l,p;
   int b[1201],f[1201],a[27][20],g[1201][3];
   fscanf(font,"%d%*c",&n);
   memset(a,0,sizeof(a));
   for (i=0;i<n;i++)
      scan(font,&a[i/20][i%20]);
   memset(bit,0,sizeof(bit));
   fscanf(in,"%d%*c",&n);
   for (i=1;i<=n;i++)
      scan(in,&b[i]);
   memset(g,26,sizeof(g));
   for (i=1;i<1<<20;i++)
      bit[i]=bit[i>>1]+(i&1);
   for (l=1;l<=n;l++)
   {
      if (l+18<=n)
         for (k=0;k<20;k++)
            for (i=0;i<27;i++)
            {
               p=0;
               for (j=0;j<20;j++)
                  if (j!=k)
                     p+=bit[a[i][j]^b[l+j-(j>k)]];
               if (g[l][0]>p)
               {
                  g[l][0]=p;
                  c[l][0]=letter[i];
               }
            }
      if (l+19<=n)
         for (i=0;i<27;i++)
         {
            p=0;
            for (j=0;j<20;j++)
               p+=bit[a[i][j]^b[l+j]];
            if (g[l][1]>p)
            {
               g[l][1]=p;
               c[l][1]=letter[i];
            }
         }
      if (l+20<=n)
         for (k=0;k<21;k++)
            for (i=0;i<27;i++)
            {
               p=0;
               for (j=0;j<21;j++)
                  if (j!=k)
                     p+=bit[a[i][j-(j>k)]^b[l+j]];
               if (g[l][2]>p)
               {
                  g[l][2]=p;
                  c[l][2]=letter[i];
               }
            }
   }
   memset(f,26,sizeof(f));
   f[0]=0;
   for (i=19;i<=n;i++)
   {
      f[i]=f[i-19]+g[i-18][0];
      prev[i]=i-19;
      j=f[i-20]+g[i-19][1];
      if (i>=20 && f[i]>j)
      {
         f[i]=j;
         prev[i]=i-20;
      }
      j=f[i-21]+g[i-20][2];
      if (i>=21 && f[i]>j)
      {
         f[i]=j;
         prev[i]=i-21;
      }
   }
   print(n);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void scan(FILE *in,int *x)
{
   char ch;
   int i;
   *x=0;
   for (i=0;i<20;i++)
   {
      *x<<=1;
      fscanf(in,"%c",&ch);
      if (ch=='1')
         *x|=1;
      else
         *x|=0;
   }
   fscanf(in,"%*c");
}
void print(int x)
{
   if (x==0)
      return;
   print(prev[x]);
   fprintf(out,"%c",c[prev[x]+1][x-prev[x]-19]);
}
