/*
ID: liuq9011
LANG: C++
TASK: fact4
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("fact4.in","r");
   out=fopen("fact4.out","w");
   int i,x,n;
   fscanf(in,"%d",&n);
   x=1;
   for (i=1;i<=n;i++)
   {
      x*=i;
      while (x%10==0)
         x/=10;
      x%=10000;
   }
   fprintf(out,"%d\n",x%10);
   fclose(in),fclose(out);
   return(0);
}
