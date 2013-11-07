/*
ID: liuq9011
LANG: C++
TASK: runround
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("runround.in","r");
   out=fopen("runround.out","w");
   int check(int);
   int m;
   fscanf(in,"%d",&m);
   while (1)
   {
      m++;
      if (check(m))
         break;
   }
   fprintf(out,"%d\n",m);
   fclose(in),fclose(out);
   return(0);
}
int check(int x)
{
   int i,j,k,t,y,n;
   int a[26],f[10];
   memset(f,0,sizeof(f));
   n=0;
   while (x!=0)
   {
      n++;
      a[n]=x%10;
      f[a[n]]++;
      x/=10;
   }
   if (f[0])
      return(0);
   for (i=1;i<=9;i++)
      if (f[i]>1)
         return(0);
   k=n;
   y=a[k];
   f[y]--;
   for (i=1;i<=n-1;i++)
   {
      t=a[k];
      for (j=1;j<=t;j++)
      {
         k--;
         if (k==0)
            k=n;
      }
      f[a[k]]--;
   }
   t=a[k];
   for (i=1;i<=t;i++)
   {
      k--;
      if (k==0)
         k=n;
   }
   if (y!=a[k])
      return(0);
   for (i=1;i<=9;i++)
      if (f[i]>0)
         return(0);
   return(1);
}
