/*
ID: liuq9011
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[1000000];
int main()
{
   in=fopen("milk2.in","r");
   out=fopen("milk2.out","w");
   int i,j,n,x,y,k,t,s1,s2,max1,max2;
   fscanf(in,"%d",&n);
   t=max1=max2=0;
   k=10000000;
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%d",&x,&y);
      if (x<k)
         k=x;
      if (y>t)
         t=y;
      for (j=x+1;j<=y;j++)
         a[j]=1;
   }
   s1=s2=0;
   for (i=k+1;i<=t;i++)
      if (a[i])
      {
         s1++;
         if (s2>max2)
            max2=s2;
         s2=0;
      }
      else
      {
         s2++;
         if (s1>max1)
            max1=s1;
         s1=0;
      }
   if (s1>max1)
      max1=s1;
   if (s2>max2)
      max2=s2;
   fprintf(out,"%d %d\n",max1,max2);
   fclose(in),fclose(out);
   return(0);
}
