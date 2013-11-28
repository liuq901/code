/*
ID: liuq9011
LANG: C++
TASK: frac1
*/
#include <cstdio>
FILE *in,*out;
double a[100000];
int b[2][100000];
int main()
{
   in=fopen("frac1.in","r");
   out=fopen("frac1.out","w");
   int gcd(int,int);
   void sort(int,int);
   int i,j,n,t;
   fscanf(in,"%d",&n);
   fprintf(out,"0/1\n");
   t=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=i-1;j++)
         if (gcd(j,i)==1)
         {
            t++;
            b[0][t]=j;
            b[1][t]=i;
            a[t]=(double)j/i;
         }
   sort(1,t);
   for (i=1;i<=t;i++)
      fprintf(out,"%d/%d\n",b[0][i],b[1][i]);
   fprintf(out,"1/1\n");
   fclose(in),fclose(out);
   return(0);
}
int gcd(int x,int y)
{
   if (y==0)
      return(x);
   else
      return(gcd(y,x%y));
}
void sort(int l,int r)
{
   int i,j,t;
   double x,s;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         s=a[i],a[i]=a[j],a[j]=s;
         t=b[0][i],b[0][i]=b[0][j],b[0][j]=t;
         t=b[1][i],b[1][i]=b[1][j],b[1][j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
