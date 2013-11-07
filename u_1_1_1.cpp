/*
ID: liuq9011
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("ride.in","r");
   out=fopen("ride.out","w");
   char a[10],b[10];
   int i,x,y;
   fscanf(in,"%s",a);
   fscanf(in,"%s",b);
   x=y=1;
   for (i=0;i<strlen(a);i++)
      x*=a[i]-'A'+1;
   for (i=0;i<strlen(b);i++)
      y*=b[i]-'A'+1;
   if (x%47==y%47)
      fprintf(out,"GO\n");
   else
      fprintf(out,"STAY\n");
   fclose(in),fclose(out);
   return(0);
}
