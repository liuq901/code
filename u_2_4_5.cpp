/*
ID: liuq9011
LANG: C++
TASK: fracdec
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[100000],f[100001];
int main()
{
   in=fopen("fracdec.in","r");
   out=fopen("fracdec.out","w");
   int i,n,m,x,t,s,sum,flag;
   fscanf(in,"%d%d",&n,&m);
   fprintf(out,"%d",n/m);
   x=n/m;
   sum=0;
   if (x==0)
      sum++;
   while (x!=0)
   {
      sum++;
      x/=10;
   }
   x=n%m;
   if (x==0)
      fprintf(out,".0\n");
   else
   {
      fprintf(out,".");
      sum++;
      memset(f,0,sizeof(f));
      f[x]=1;
      s=0;
      while (1)
      {
         t=x*10;
         s++;
         a[s]=t/m;
         x=t%m;
         if (x==0)
         {
            for (i=1;i<=s;i++)
            {
               fprintf(out,"%d",a[i]);
               sum++;
               if (sum==76)
               {
                  sum=0;
                  fprintf(out,"\n");
               }
            }
            fprintf(out,"\n");  
            break;
         }
         if (f[x])
         {
            t=x*10/m;
            flag=1;
            for (i=1;i<=s;i++)
            {
               if (t==a[i] && flag)
               {
                  fprintf(out,"(");
                  sum++;
                  flag=0;
               }
               fprintf(out,"%d",a[i]);
               sum++;
               if (sum==76)
               {
                  sum=0;
                  fprintf(out,"\n");
               }
            }
            fprintf(out,")\n");
            break;
         }
         f[x]=1;
      }
   }
   fclose(in),fclose(out);
   return(0);
}
