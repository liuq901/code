/*
ID: liuq9011
LANG: C++
TASK: test
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("test.in","r");
   out=fopen("test.out","w");
   int a,b;
   fscanf(in,"%d%d",&a,&b);
   fprintf(out,"%d\n",a+b);
   fclose(in),fclose(out);
   return(0);
}
