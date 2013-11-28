/*
ID: liuq9011
LANG: C++
TASK: sprime
*/
#include <cstdio>
#include <cmath>
FILE *in,*out;
int n;
int main()
{
   in=fopen("sprime.in","r");
   out=fopen("sprime.out","w");
   void check(int,int);
   fscanf(in,"%d",&n);
   if (n==1)
   {
      fprintf(out,"2\n");
      fprintf(out,"3\n");
      fprintf(out,"5\n");
      fprintf(out,"7\n");
   }
   else
   {
      check(1,2);
      check(1,3);
      check(1,5);
      check(1,7);
   }
   fclose(in),fclose(out);
   return(0);
}
void check(int x,int m)
{
   int ss(int);
   int t,i;
   for (i=1;i<=5;i++)
   {
      t=m*10+2*i-1;
      if (ss(t))
         if (x==n-1)
            fprintf(out,"%d\n",t);
         else
            check(x+1,t);
   }
}
int ss(int x)
{
   int i,flag;
   flag=1;
   for (i=2;i<sqrt(x)+1;i++)
      if (x%i==0)
      {
         flag=0;
         break;
      }
   return(flag);
}
