/*
ID: liuq9011
LANG: C++
TASK: hamming
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
FILE *in,*out;
int n,b,c,d,a[100];
int main()
{
   in=fopen("hamming.in","r");
   out=fopen("hamming.out","w");
   void search(int);
   int i;
   fscanf(in,"%d%d%d",&n,&b,&d);
   c=(int)(pow(2,b)+0.5)-1;
   for (i=0;i<=c;i++)
   {
      a[1]=i;
      search(1);
   }
}
void search(int x)
{
   int check(int,int);
   void print();
   int i;
   if (a[x]>c)
      return;
   for (i=1;i<=x-1;i++)
      if (check(a[i],a[x])<d)
         return;
   if (x==n)
      print();
   for (i=a[x]+1;i<=c;i++)
   {
      a[x+1]=i;
      search(x+1);
   }
}
int check(int x,int y)
{
   int s,i;
   s=i=0;
   while (1)
   {
      i++;
      if (x%2!=y%2)
         s++;
      x/=2;
      y/=2;
      if (i==b)
         break;
   }
   return(s);
}
void print()
{  
   int i; 
   for (i=1;i<=n-1;i++)
   {
      fprintf(out,"%d",a[i]);
      if (i%10==0)
         fprintf(out,"\n");
      else
         fprintf(out," ");
   }
   fprintf(out,"%d\n",a[n]);
   fclose(in),fclose(out);
   exit(0);
}
