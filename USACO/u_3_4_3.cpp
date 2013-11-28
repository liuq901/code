/*
ID: liuq9011
LANG: C++
TASK: fence9
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
FILE *in,*out;
int main()
{
   int gcd(int,int);
   in=fopen("fence9.in","r");
   out=fopen("fence9.out","w");
   int n,m,p,s,x,ans;
   fscanf(in,"%d%d%d",&n,&m,&p);
   s=p*m/2;
   x=0;
   x=p+gcd(m,n)+gcd(abs(p-n),m);
   ans=s-x/2+1;
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int gcd(int x,int y)
{
   if (x==0)
      return(y);
   if (y==0)
      return(x);
   return(gcd(y,x%y));
}
