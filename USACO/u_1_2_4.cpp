/*
ID: liuq9011
LANG: C++
TASK: palsquare
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("palsquare.in","r");
   out=fopen("palsquare.out","w");
   void check(int,int);
   int i,n;
   fscanf(in,"%d",&n);
   for (i=1;i<=300;i++)
      check(i,n);
   fclose(in),fclose(out);
   return(0);
}
void check(int x,int n)
{
   int i,t,flag;
   int a[100],b[100];
   t=x*x;
   i=0;
   while (t!=0)
   {
      i++;
      a[i]=t%n;
      t/=n;
   }
   a[0]=i;
   flag=1;
   for (i=1;i<=a[0]/2;i++)
      if (a[i]!=a[a[0]-i+1])
      {
         flag=0;
         break;
      }
   if (flag)
   {
      i=0;
      while (x!=0)
      {
         i++;
         b[i]=x%n;
         x/=n;
      }
      b[0]=i;
      for (i=b[0];i>=1;i--)
         if (b[i]<10)
            fprintf(out,"%d",b[i]);
         else
            fprintf(out,"%c",b[i]-10+'A');
      fprintf(out," ");
      for (i=1;i<=a[0];i++)
         if (a[i]<10)
            fprintf(out,"%d",a[i]);
         else
            fprintf(out,"%c",a[i]-10+'A');
      fprintf(out,"\n");
   }
}
