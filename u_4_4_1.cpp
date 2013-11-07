/*
ID: liuq9011
LANG: C++
TASK: shuttle
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("shuttle.in","r");
   out=fopen("shuttle.out","w");
   int n,i,j,s,p,q;
   int a[1000];
   fscanf(in,"%d",&n);
   s=1;
   a[1]=n;
   p=-2;
   q=-1;
   for (i=1;i<=n-1;i++)
   {
      p*=-1;
      q*=-1;
      for (j=1;j<=i;j++)
      {
         s++;
         a[s]=a[s-1]+p;
      }
      s++;
      a[s]=a[s-1]+q;
   }
   p*=-1;
   q*=-1;
   for (i=1;i<=n;i++)
   {
      s++;
      a[s]=a[s-1]+p;
   }
   for (i=n-1;i>=1;i--)
   {
      p*=-1;
      q*=-1;
      s++;
      a[s]=a[s-1]+q;
      for (j=1;j<=i;j++)
      {
         s++;
         a[s]=a[s-1]+p;
      }
   }
   q*=-1;
   s++;
   a[s]=a[s-1]+q;
   for (i=1;i<=s-1;i++)
   {
      fprintf(out,"%d",a[i]);
      if (i%20==0)
         fprintf(out,"\n");
      else
         fprintf(out," ");
   }
   fprintf(out,"%d\n",a[s]);
   fclose(in),fclose(out);
   return(0);
}
