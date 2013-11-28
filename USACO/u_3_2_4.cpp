/*
ID: liuq9011
LANG: C++
TASK: ratios
*/
#include <cstdio>
FILE *in,*out;
int x,y,z,x1,y1,z1,x2,y2,z2,x3,y3,z3;
int main()
{
   in=fopen("ratios.in","r");
   out=fopen("ratios.out","w");
   int check(int,int,int);
   int i,j,k,s1,s2,s3,s,ans;
   fscanf(in,"%d%d%d",&x,&y,&z);
   fscanf(in,"%d%d%d",&x1,&y1,&z1);
   fscanf(in,"%d%d%d",&x2,&y2,&z2);
   fscanf(in,"%d%d%d",&x3,&y3,&z3);
   s=2000000;
   for (i=0;i<100;i++)
   {
      for (j=0;j<100;j++)
         for (k=0;k<100;k++)
            if (i+j+k!=0 && check(i,j,k)!=0)
               if (i+j+k<s)
               {
                  s1=i;
                  s2=j;
                  s3=k;
                  s=i+j+k;
                  ans=check(i,j,k);
               }
   }
   if (s==2000000)
      fprintf(out,"NONE\n");
   else
      fprintf(out,"%d %d %d %d\n",s1,s2,s3,ans);
   fclose(in),fclose(out);
   return(0);
}
int check(int t1,int t2,int t3)
{
   int m,n;
   m=t1*x1+t2*x2+t3*x3;
   if (x!=0)
      n=m/x;
   if (x!=0)
      if (m%x!=0)
         return(0);
   if (x==0 && m!=0)
      return(0);
   m=t1*y1+t2*y2+t3*y3;
   if (x==0)
      if (y!=0)
         n=m/y;
   if (y!=0)
      if (m%y!=0 || m/y!=n)
         return(0);
   if (y==0 && m!=0)
      return(0);
   m=t1*z1+t2*z2+t3*z3;
   if (x==0 && y==0)
      if (z!=0)
         n=m/z;
   if (z!=0)
      if (m%z!=0 || m/z!=n)
         return(0);
   if (z==0 && m!=0)
      return(0);
   return(n);
}
