/*
ID: liuq9011
LANG: C++
TASK: nuggets
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("nuggets.in","r");
   out=fopen("nuggets.out","w");
   int gcd(int,int);
   int n,i,j,x,y,s,z;
   int a[26],f[70000];
   fscanf(in,"%d",&n);
   memset(f,0,sizeof(f));
   x=y=z=0;
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d",&a[i]);
      if (a[i]==1)
      {
         z=26;
         break;
      }
      f[a[i]]=1;
      if (a[i]>x)
      {
         y=x;
         x=a[i];
      }
      else if (a[i]>y)
         y=a[i];
      if (z==0 && i==2)
         z=gcd(a[1],a[2]);
      else if (z!=0)
         z=gcd(z,a[i]);
   }
   if (z!=1)
      fprintf(out,"0\n");
   else
   {
      s=x/gcd(x,y)*y;
      for (i=1;i<=s;i++)
      {
         if (!f[i])
            continue;
         for (j=1;j<=n;j++)
            f[i+a[j]]=1;
      }
      for (i=s;i>=0;i--)
         if (!f[i])
            break;
      fprintf(out,"%d\n",i);
   }
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
