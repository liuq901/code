/*
ID: liuq9011
LANG: C++
TASK: dualpal
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("dualpal.in","r");
   out=fopen("dualpal.out","w");
   int check(int);
   int i,k,n,s;
   fscanf(in,"%d%d",&n,&s);
   i=s;
   k=0;
   while (1)
   {
      i++;
      if (check(i))
      {
         fprintf(out,"%d\n",i);
         k++;
      }
      if (k==n)
         break;
   }
   fclose(in),fclose(out);
   return(0);
}
int check(int x)
{
   int work(int,int);
   int i,s;
   s=0;
   for (i=2;i<=10;i++)
   {
      if (work(x,i))
         s++;
      if (s==2)
         break;
   }
   if (s==2)
      return(1);
   else
      return(0);
}
int work(int x,int n)
{
   int i;
   int a[100];
   i=0;
   while (x!=0)
   {
      i++;
      a[i]=x%n;
      x/=n;
   }
   a[0]=i;
   for (i=1;i<=a[0]/2;i++)
      if (a[i]!=a[a[0]-i+1])
         return(0);
   return(1);
}
